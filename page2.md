@page page2  Future additions

More rules can easily be added using this algo 

for rules involving assumptions-
when the rule of a statement is assumption we can store all the statements from this statement onwards in a different global variable.
when a rule which ends the assumption is used we can again start storing the statements from this point forward in the statement golobal variable and we can delete the statments stored in the assumption global variable;

example --
impl intro :
we make assumption and then when user weites statement with rule
/>i/1/4
then we can check first and 4 th statement in the assumption vzriable if it matches then the statement is correct and it is stored in the statement global variable
and the assumption variable is cleared ;
note-
the statements 2,3,4 will be checked as normal statements using the normal functions

and after the box is closed(assumption global variable is cleared)
no one can access statment 2,3,4 as it is not present in the statemt variable and even not present in the assumption variable.
