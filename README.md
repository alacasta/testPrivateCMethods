

# testPrivateCMethods
This repository has been created to provide an solution for testing/call those private methods that sometimes should be needed for creating preconditions in the test considering that these are sometimes not puclicly exposed

## Use case
I am interested in analyzing that case where some private method like
```
void _changeMyVariable()
{
  _myVariable = False
}
```

can be called externally (somebody defined such callback to be defined) and the public method to be tested depends on changes produced by that method (i.e  test the branch of the public method like)
```
void myPublicMethodToBeTested()
{
  if _myVariable
  {
      // Call Whatever
  }
}
```

We can discuss wether such situation should be enforced or all the mechanisms needed to reach such situations should be triggered. However, simplified test preconditions when testing internals make sense also. To do that, you'd usually requires to use that private method _changeMyVariable() from the test case so that the precondition is satisfied. Again, how this method is called from the logical point of view is out of discussion.

## Practical application
Given the library lib/customOps which has the following interface

```
/*
	customOps.h
*/

// Returns the value of the private variable _myPrivateVariable defined in the 
// .c file. To mofify that variable, the private method modifyMyPrivateVariable 
// should be called. Of course, this can be only performed internally by the 
// library (at least in theory...)
int returnTrueIfAPrivateMethodIsCalled();

```
the method returnTrueIfAPrivateMethodIsCalled is needed to be tested. Basically, it returns true (something different from 0) if someone modify some ineternal value. Let's see the code...

```
int returnTrueIfAPrivateMethodIsCalled()
{
	if(_myPrivateVariable)
	{
		return 1;
	}
	return 0;
}
```
it's clear that the trivial case is when _myPrivateVariable is false, however, we'd liek to test both branches. The library provides a private mechanism like
```
void modifyMyPrivateVariable(int value)
{
	_myPrivateVariable = value;
}
```
whose interface is not exposed. Therefore, we need to call that method from the test to "simulate" such situation 

```
TEST(CustomOps, VerifyThatTheMethodReturnsOne) {
  // Modify the internal variable
	modifyMyPrivateVariable(1);
  // Check that the returned value was modify accordingly
	EXPECT_EQ(1, returnTrueIfAPrivateMethodIsCalled());

}
```
The tricky part here is to provide some *friend-like* mechanism to solve this. One solution may be to define its (no-so) public API like

```
extern "C" void modifyMyPrivateVariable(int value);
```

so that the compiler knows how the method looks like and then the linker will finally solve the situation.

## Additional comments
Let me insisct in the fact about that this situation should never occured since internal mechanisms might be abstracted somehow in order to follow an accurate architecture. This is only provided as an example about how to proceed when complex mechanisms should be analyzed by manuipulating "internals"



