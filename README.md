

# testPrivateCMethods
This repository has been created to provide an solution for testing/call those private methods that sometimes should be needed for creating preconditions in the test considering that these are sometimes not puclicly exposed

## Use case
The typical case where we have some private method like
```
void _changeMyVariable()
{
  _myVariable = False
}
```

but we want to test the branch of the public method like
```
void myPublicMethodToBeTested()
{
  if myVariable
  {
      // Call Whatever
  }
}
```
usually requires to use that private method _changeMyVariable() from the test case so that the precondition is satisfied.
