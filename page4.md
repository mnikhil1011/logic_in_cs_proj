@page page3 algorithm

in this code 

the input is split in the main function with the help of the first / 
input before/ is statment and input after / is rule

all statements are saved in the global variable called "valid"

algo for the functions
1)and intro , and elem function
in these functions a statement is derived using the rule if the statement matched the statement provided by the user then it is a valid statement 
-statement is derived in the following way-
and intro- 
    we first add ( then copy the statement in the first  number of the rule then add ^ then copy the statement in the second  number of the rule then add ) 
    if this statement is same as the statement provided then it is valid

and elem-
    if it is and elem 1, then we traverse the statement from the second char(because the first char will be a '(') if we reach another open bracket we do see++(a local variable) when we encounter a close bracket see-- we keep traversing till we find  an and symbol when see is 0. we copy the statement till here if it matches with statement provided then its a valid proof

    if its and elem 2 after encountering the and when see is 0 we copy the statement from there till the end and the last ')' is exchanged with ' 'if it matches with statement provided then its a valid proof

2)or intro , impl elem ,mt 
in these functions the statements are checked using the previous statements and matching them with the statement provided by the user if the statements get matched 
then it is a valid statement 
or intro-
    in this function we check if the brackets are there and we check if the statement after(if y=2) the | is same
    or before(if y=1) | is same as the statement of the second number in the rule.
    the location of | is found using the same algo used in and elem for finding ^

impl elem -
    statement 2 is matched with the first part of statement 1, statement 1 should have everything same as statement 1 and a '(' before it and a '>' after it
    then it is matched with the statement provided with the rule this statement should be same as the statement after >

mt-
    this  is similar to impl elem but here statement provided is first matched and then statement 2 is matched with statement 1
    matching is done after the ~ sign. first it is checked if they have ~ then they are matched

    when the statement is in the form of ~(~x) then another case should me made as in the implied sign the brackets wont exist and it would simply be ~x, so an if else is added for this case.

