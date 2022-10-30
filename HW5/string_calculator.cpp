#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout ;
using std::endl ;
using std::string;


unsigned int digit_to_decimal(char digit) 
{
    // TODO(student): implement

    int num ;
    // for(i = 0 ; i < digit.length(); i++)
    // {
    //     if(digit[i] == ("0" || "1" || "2" || "3" || "4" || "5" || "6" || "7" || "8" || "9" || "0"))
    //     num = int(digit[i])
    //     else
    //     std::invalid_argument("NOt a digit") ;
    // }

    if(digit == '0' || digit == '1' || digit == '2' || digit == '3' || digit == '4' || digit == '5' || digit == '6' || digit == '7' || digit == '8' || digit == '9')
    num = int(digit) - int(48);
    else
    {
        cout << digit << " ERROR" << endl ;
        throw std::invalid_argument("NOt a digit") ;
    }
    
    cout << num << endl ;
    // cout << int(digit) << " " << typeid(int(digit)) << endl ;
    // cout << digit - 48 << " " << typeid(digit - 48) << endl ;
    //cout << int(digit) - 48 << endl ;

    return num;
}

char decimal_to_digit(unsigned int decimal) 
{
    // TODO(student): implement

    char digit ;
 
    if(decimal == 0)
    digit = char(48) ;
    else if (decimal == 1)
    digit = char(49) ;
    else if (decimal == 2)
    digit = char(50) ;
    else if (decimal == 3)
    digit = char(51) ;
    else if (decimal == 4)
    digit = char(52) ;
    else if (decimal == 5)
    digit = char(53) ; 
    else if (decimal == 6)
    digit = char(54) ;
    else if (decimal == 7)
    digit = char(55) ;
    else if (decimal == 8)
    digit = char(56) ;
    else if (decimal == 9)
    digit = char(57) ;
    else
    throw std::invalid_argument("INvalid deicmal") ;

  //  cout << digit ;
   // cout << "decimal is: " << decimal << " digit is: " << digit << endl ;
    return digit ; 
}

string trim_leading_zeros(string num) {

    int length = num.length() ;

    // if(num[0] == 0)
    // {
    //     num.erase(0, num.find_first_not_of('0')) ;
    //     return string(num) ;
    // }

    

    // for(int i = 0 ; i < num.length() ; i++)
    // {
    //     while(num[i] == 0)
    //     {
    //         number = "0" ;
    //     }
    // }
    // return number;
    cout <<"num is: " << num << endl ;

    int i = 0 ;

    bool negative = num[0]=='-' ;
    while(i < length && (num[i] == '0' || num[i] == '-'))
    {
        i++ ;
    }

    if(i == length)
    {
    num = "0" ;
    return num ;
    }

    num = num.substr(i , length);
    if(negative)
    {
        num.insert(0 , 1 , '-') ;
    }

    return num ;
    
}

string subtract(string lhs, string rhs) {
    bool something = true;
    //positive, positive
    if((lhs.at(0) == '0' || lhs.at(0) == '1'|| lhs.at(0) == '2'|| lhs.at(0) == '3'|| lhs.at(0) == '4'|| lhs.at(0) == '5'|| lhs.at(0) == '6'|| lhs.at(0) == '7'|| lhs.at(0) == '8'|| lhs.at(0) == '9') && (rhs.at(0) == '0' || rhs.at(0) == '1'|| rhs.at(0) == '2'|| rhs.at(0) == '3'|| rhs.at(0) == '4'|| rhs.at(0) == '5'|| rhs.at(0) == '6'|| rhs.at(0) == '7'|| rhs.at(0) == '8'|| rhs.at(0) == '9')){
        if(lhs.size() > rhs.size()){                                                    //adds leading zeros to right hand side number
            lhs.insert(0,"0");
            for(int i = 0; i < (int)lhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    rhs.insert(0,"0");
                }
            }

            int takeAway = 0;
            int result = 0;
            string stringResult = "";
            int digitResult = 0;
            
            for(int i = lhs.size()-1; i > 0; i--){
                int leftDigit = digit_to_decimal(lhs.at(i));
                int rightDigit = digit_to_decimal(rhs.at(i));
                digitResult = (leftDigit - rightDigit);
                if(takeAway != 0){
                    digitResult = ((leftDigit-1) - rightDigit);
                    leftDigit -= 1;
                }
                else if(takeAway == 0){
                    digitResult = (leftDigit - rightDigit);
                }
                if(digitResult < 0){
                    takeAway = 1;
                    result = (leftDigit + 10) - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
                if(digitResult >= 0){
                    takeAway = 0;
                    result = leftDigit - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
            }
            return trim_leading_zeros(stringResult);

        }
        else if(lhs.size() < rhs.size()){                                               //adds leading zeros to left hand side number
            rhs.insert(0,"0");
            for(int i = 0; i < (int)rhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    lhs.insert(0,"0");
                }
            }

            lhs.swap(rhs);
            
            int takeAway = 0;
            int result = 0;
            string stringResult = "";
            int digitResult = 0;
            
            for(int i = lhs.size()-1; i > 0; i--){
                int leftDigit = digit_to_decimal(lhs.at(i));
                int rightDigit = digit_to_decimal(rhs.at(i));
                digitResult = (leftDigit - rightDigit);
                if(takeAway != 0){
                    digitResult = ((leftDigit-1) - rightDigit);
                    leftDigit -= 1;
                }
                else if(takeAway == 0){
                    digitResult = (leftDigit - rightDigit);
                }
                if(digitResult < 0){
                    takeAway = 1;
                    result = (leftDigit + 10) - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
                if(digitResult >= 0){
                    takeAway = 0;
                    result = leftDigit - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
            }
            return "-" + trim_leading_zeros(stringResult);

        }
        else if(lhs.size() == rhs.size()){
            if(lhs == rhs){
                return "0";
            }
            lhs.insert(0,"0");
            rhs.insert(0,"0");

            for(int i = 1; i < (int)lhs.size(); i++){
                    if(digit_to_decimal(lhs.at(i)) < digit_to_decimal(rhs.at(i))){
                        lhs.swap(rhs);
                        something = false;
                        cout << "something is false" << endl;
                        break;
                    }
                    else if(digit_to_decimal(lhs.at(i)) > digit_to_decimal(rhs.at(i))){
                        break;
                    }
            }

            int takeAway = 0;
            int result = 0;
            string stringResult = "";
            int digitResult = 0;
            
            for(int i = lhs.size()-1; i > 0; i--){
                int leftDigit = digit_to_decimal(lhs.at(i));
                int rightDigit = digit_to_decimal(rhs.at(i));
                digitResult = (leftDigit - rightDigit);
                if(takeAway != 0){
                    digitResult = ((leftDigit-1) - rightDigit);
                    leftDigit -= 1;
                }
                else if(takeAway == 0){
                    digitResult = (leftDigit - rightDigit);
                }
                if(digitResult < 0){
                    takeAway = 1;
                    result = (leftDigit + 10) - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
                if(digitResult >= 0){
                    takeAway = 0;
                    result = leftDigit - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
            }
            
            if(something == false){
                return "-" + trim_leading_zeros(stringResult);
            }
            else if (something == true){
                return trim_leading_zeros(stringResult);
            }           
        }
    }

    //negative, negative
    else if(lhs.at(0) == '-' && rhs.at(0) == '-'){
        if(lhs == rhs){
            return "0";
        }
        bool something2 = false;
        lhs.erase(0,1);
        rhs.erase(0,1);

        if(lhs.size() > rhs.size()){                                                    //adds leading zeros to right hand side number
            lhs.insert(0,"0");
            for(int i = 0; i < (int)lhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    rhs.insert(0,"0");
                }
            }

            int takeAway = 0;
            int result = 0;
            string stringResult = "";
            int digitResult = 0;
            
            for(int i = lhs.size()-1; i > 0; i--){
                int leftDigit = digit_to_decimal(lhs.at(i));
                int rightDigit = digit_to_decimal(rhs.at(i));
                digitResult = (leftDigit - rightDigit);
                if(takeAway != 0){
                    digitResult = ((leftDigit-1) - rightDigit);
                    leftDigit -= 1;
                }
                else if(takeAway == 0){
                    digitResult = (leftDigit - rightDigit);
                }
                if(digitResult < 0){
                    takeAway = 1;
                    result = (leftDigit + 10) - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
                if(digitResult >= 0){
                    takeAway = 0;
                    result = leftDigit - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
            }
            return "-" + trim_leading_zeros(stringResult);

        }
        else if(lhs.size() < rhs.size()){                                               //adds leading zeros to left hand side number
            rhs.insert(0,"0");
            for(int i = 0; i < (int)rhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    lhs.insert(0,"0");
                }
            }

            lhs.swap(rhs);
            
            int takeAway = 0;
            int result = 0;
            string stringResult = "";
            int digitResult = 0;
            
            for(int i = lhs.size()-1; i > 0; i--){
                int leftDigit = digit_to_decimal(lhs.at(i));
                int rightDigit = digit_to_decimal(rhs.at(i));
                digitResult = (leftDigit - rightDigit);
                if(takeAway != 0){
                    digitResult = ((leftDigit-1) - rightDigit);
                    leftDigit -= 1;
                }
                else if(takeAway == 0){
                    digitResult = (leftDigit - rightDigit);
                }
                if(digitResult < 0){
                    takeAway = 1;
                    result = (leftDigit + 10) - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
                if(digitResult >= 0){
                    takeAway = 0;
                    result = leftDigit - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
            }
            return trim_leading_zeros(stringResult);

        }
        else if(lhs.size() == rhs.size()){
            lhs.insert(0,"0");
            rhs.insert(0,"0");
            
            for(int i = 1; i < (int)lhs.size(); i++){
                    if(digit_to_decimal(lhs.at(i)) < digit_to_decimal(rhs.at(i))){
                        lhs.swap(rhs);
                        something2 = true;
                        break;
                    }
                    else if(digit_to_decimal(lhs.at(i)) > digit_to_decimal(rhs.at(i))){
                        break;
                    }
            }   

            int takeAway = 0;
            int result = 0;
            string stringResult = "";
            int digitResult = 0;
            
            for(int i = lhs.size()-1; i > 0; i--){
                int leftDigit = digit_to_decimal(lhs.at(i));
                int rightDigit = digit_to_decimal(rhs.at(i));
                digitResult = (leftDigit - rightDigit);
                if(takeAway != 0){
                    digitResult = ((leftDigit-1) - rightDigit);
                    leftDigit -= 1;
                }
                else if(takeAway == 0){
                    digitResult = (leftDigit - rightDigit);
                }
                if(digitResult < 0){
                    takeAway = 1;
                    result = (leftDigit + 10) - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
                if(digitResult >= 0){
                    takeAway = 0;
                    result = leftDigit - rightDigit;
                    string empty = "";
                    stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
                }
            }

            if(something2 == false){
                return "-" + trim_leading_zeros(stringResult);
            }
            else if (something2 == true){
                return trim_leading_zeros(stringResult);
            }            
        }

    }

    //positive, negative
    else if((lhs.at(0) == '0' || lhs.at(0) == '1'|| lhs.at(0) == '2'|| lhs.at(0) == '3'|| lhs.at(0) == '4'|| lhs.at(0) == '5'|| lhs.at(0) == '6'|| lhs.at(0) == '7'|| lhs.at(0) == '8'|| lhs.at(0) == '9') && (rhs.at(0) == '-')){
        rhs.erase(0,1);
        return add(lhs,rhs);
    }

    //negative, positive
    else if((lhs.at(0) == '-') && (rhs.at(0) == '1'|| rhs.at(0) == '2'|| rhs.at(0) == '3'|| rhs.at(0) == '4'|| rhs.at(0) == '5'|| rhs.at(0) == '6'|| rhs.at(0) == '7'|| rhs.at(0) == '8'|| rhs.at(0) == '9')){
        lhs.erase(0,1);
        return "-" + add(lhs,rhs);
    }
    return "";
}

string add(string lhs, string rhs) {
    if(lhs.at(0) == '-' && rhs.at(0) == '0'){
        return lhs;
    }
    if(rhs.at(0) == '-' && lhs.at(0) == '0'){
        return rhs;
    }
    //positive, positive
    if((lhs.at(0) == '0' || lhs.at(0) == '1'|| lhs.at(0) == '2'|| lhs.at(0) == '3'|| lhs.at(0) == '4'|| lhs.at(0) == '5'|| lhs.at(0) == '6'|| lhs.at(0) == '7'|| lhs.at(0) == '8'|| lhs.at(0) == '9') && (rhs.at(0) == '0' || rhs.at(0) == '1'|| rhs.at(0) == '2'|| rhs.at(0) == '3'|| rhs.at(0) == '4'|| rhs.at(0) == '5'|| rhs.at(0) == '6'|| rhs.at(0) == '7'|| rhs.at(0) == '8'|| rhs.at(0) == '9')){
        if(lhs.size() > rhs.size()){                                                    //adds leading zeros to right hand side number
            lhs.insert(0,"0");
            for(int i = 0; i < (int)lhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    rhs.insert(0,"0");
                }
            }
        }
        else if(lhs.size() < rhs.size()){                                               //adds leading zeros to left hand side number
            rhs.insert(0,"0");
            for(int i = 0; i < (int)rhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    lhs.insert(0,"0");
                }
            }
        }
        else if(lhs.size() == rhs.size()){
            lhs.insert(0,"0");
            rhs.insert(0,"0");
        }   

        int carry = 0;
        string stringResult = "";
        int result = 0;
        for(int i = lhs.size()-1; i >= 0; i--){
            int leftDigit = digit_to_decimal(lhs.at(i));
            int rightDigit = digit_to_decimal(rhs.at(i));
            int digitResult = (leftDigit + rightDigit) + carry;
            if(digitResult > 9){
                string empty = "";
                carry = 1;
                result = (digitResult - 10);
                stringResult.insert(0,empty.assign(1,decimal_to_digit(result)));
            }
            else if(digitResult < 10){
                carry = 0;
                string empty = "";
                stringResult.insert(0,empty.assign(1,decimal_to_digit(digitResult)));
            }
        }
        return trim_leading_zeros(stringResult);
    }

    //negative, negative
    else if(lhs.at(0) == '-' && rhs.at(0) == '-'){
        if(lhs.size() > rhs.size()){                                                    //adds leading zeros to right hand side number
            lhs.insert(1,"0");
            for(int i = 0; i < (int)lhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    rhs.insert(1,"0");
                }
            }
        }
        else if(lhs.size() < rhs.size()){                                               //adds leading zeros to left hand side number
            rhs.insert(1,"0");
            for(int i = 0; i < (int)rhs.size(); i++){
                while(lhs.size() != rhs.size()){
                    lhs.insert(1,"0");
                }
            }
        }
        else if(lhs.size() == rhs.size()){
            lhs.insert(1,"0");
            rhs.insert(1,"0");
        }

    int carry = 0;
    string stringResult = "-";
    int result = 0;
    for(int i = lhs.size()-1; i > 0; i--){
        int leftDigit = digit_to_decimal(lhs.at(i));
        int rightDigit = digit_to_decimal(rhs.at(i));
        int digitResult = (leftDigit + rightDigit) + carry;
        if(digitResult > 9){
            string empty = "";
            carry = 1;
            result = (digitResult - 10);
            stringResult.insert(1,empty.assign(1,decimal_to_digit(result)));
        }
        else if(digitResult < 10){
            carry = 0;
            string empty = "";
            stringResult.insert(1,empty.assign(1,decimal_to_digit(digitResult)));
        }
    }
        return trim_leading_zeros(stringResult);
    }

    //positive, negative
    else if((lhs.at(0) == '0' || lhs.at(0) == '1'|| lhs.at(0) == '2'|| lhs.at(0) == '3'|| lhs.at(0) == '4'|| lhs.at(0) == '5'|| lhs.at(0) == '6'|| lhs.at(0) == '7'|| lhs.at(0) == '8'|| lhs.at(0) == '9') && (rhs.at(0) == '-')){
         rhs.erase(0,1);
         return subtract(lhs,rhs);
    }

    //negative, positive
    else if((lhs.at(0) == '-') && (rhs.at(0) == '1'|| rhs.at(0) == '2'|| rhs.at(0) == '3'|| rhs.at(0) == '4'|| rhs.at(0) == '5'|| rhs.at(0) == '6'|| rhs.at(0) == '7'|| rhs.at(0) == '8'|| rhs.at(0) == '9')){
        lhs.erase(0,1);
        lhs.swap(rhs);
        return subtract(lhs,rhs);
    }
    return "";
}



string multiply(string lhs, string rhs) 
{
    // TODO(student)
    
    // int prod, num1, num2 ;
    // string product ;

    // num1 = std::stoi(lhs) ;
    // num2 = std::stoi(rhs) ;

    // cout << "num1: " << num1 << endl ;
    // cout << "num2: " << num2 << endl ;

    // prod = num1 * num2 ;

    // product = std::to_string(prod) ;

    // cout << "product is: " << product << endl ;

    // return product ;

    int x = 0;
    int lefSize = lhs.size();
    int rightSize = rhs.size();
    int mult = 0;
    bool neg = false;
    int carry = 0;
    bool booleanCarryOver = false;

    if (lhs.at(0) == '-' && rhs.at(0) == '-'){
        lhs.at(0) = '0';
        rhs.at(0) = '0';
        lhs = trim_leading_zeros(lhs);
        rhs = trim_leading_zeros(rhs);

        lefSize = lhs.size();
        rightSize = rhs.size();
    }
    else if ((lhs.at(0) == '0' || lhs.at(0) == '1' || lhs.at(0) == '2' || lhs.at(0) == '3' || lhs.at(0) == '4' || lhs.at(0) == '5' || lhs.at(0) == '6' || lhs.at(0) == '7' || lhs.at(0) == '8' || lhs.at(0) == '9') && (rhs.at(0) == '-')){
        rhs.at(0) = '0';
        rhs = trim_leading_zeros(rhs);
        rightSize = rhs.size();
        neg = true;
    }
    else if ((lhs.at(0) == '-') && (rhs.at(0) == '0' || rhs.at(0) == '1' || rhs.at(0) == '2' || rhs.at(0) == '3' || rhs.at(0) == '4' || rhs.at(0) == '5' || rhs.at(0) == '6' || rhs.at(0) == '7' || rhs.at(0) == '8' || rhs.at(0) == '9')){
        lhs.at(0) = '0';
        lhs = trim_leading_zeros(lhs);
        lefSize = lhs.size();
        neg = true;
    }
    
    if (digit_to_decimal(lhs.at(0)) == 0 || digit_to_decimal(rhs.at(0)) == 0){
        return "0";
    }

    int sizeLittle;
    int sizeHuge;
    string stringCarry;

    if (lefSize > rightSize){
        sizeLittle = rightSize;
        sizeHuge = lefSize;
    }
    else if (lefSize < rightSize){
        sizeLittle = lefSize;
        sizeHuge = rightSize;
        stringCarry = lhs;
        lhs = rhs;
        rhs = stringCarry;
    }
    else {
        sizeLittle = lefSize;
        sizeHuge = rightSize;
    }

    string something;
    string product;
    string productInitial;
    string fin_product;

    for (int i = sizeLittle - 1; i >= 0; i--){
        for (int j = sizeHuge - 1; j >= 0; j--){
            if (booleanCarryOver){
                mult = 0;
                mult = (digit_to_decimal(lhs.at(j)) * digit_to_decimal(rhs.at(i))) + carry;
                carry = 0;
                booleanCarryOver = false;
            }
            else{
                mult = (digit_to_decimal(lhs.at(j)) * digit_to_decimal(rhs.at(i)));
            }

            if (mult >= 10){
                carry = mult / 10;
                something = decimal_to_digit(mult % 10);
                productInitial.insert(0, something);
                booleanCarryOver = true;
            }
            else{
                something = decimal_to_digit(mult);
                productInitial.insert(0, something);
            }

            if (j == 0 && booleanCarryOver){
                something = decimal_to_digit(carry);
                productInitial.insert(0, something);
                booleanCarryOver = false;
                carry = 0;
            }
        }

        if ((sizeLittle - i) == 1){
            product = productInitial;
        }
        else{
            if ((sizeLittle - i) == 2){
                productInitial.append("0");
                x++;
                fin_product = add(product, productInitial);
                carry = 0;
            }
            else{
                for (int k = 0; k <= x; k++){
                    productInitial.append("0");
                }
                x++;
                fin_product = add(productInitial, fin_product);
            }
        }

        if (i == 0 && carry >= 10){
            something = decimal_to_digit(carry);
            productInitial.insert(0, something);
        }

        if (i == 0 && sizeLittle == 1){
            fin_product = product;
        }
        productInitial.clear();
    }

    if(neg == true){
        fin_product.insert(0, "-");
    }

    return fin_product;
}