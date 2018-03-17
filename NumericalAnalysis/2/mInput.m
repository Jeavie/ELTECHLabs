function [absolute, first, second] = mInput()

first = input('Please enter the first number: ' );
second = input('Please enter the second number: ' );
while ((second - first) <= 0)
    absolute = second - first;
    if (absolute > 0)
        break;
    else
        disp('You entered wrong numbers. Try again');
        first = input('Please enter the first number: ' );
        second = input('Please enter the second number: ' );
    end
end
absolute = second - first;