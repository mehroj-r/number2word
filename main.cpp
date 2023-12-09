#include <iostream>
#include <string>
using namespace std;

string bet1_9(int num){
    switch (num){
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "None";
    }
}

string bet10_19(int num){
    switch (num){
        case 10: return "Ten";
        case 11: return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14: return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        case 19: return "Nineteen";
        default: return "None";
    }
}

string unique(int num){
    switch (num){
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Forty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        case 9: return "Ninety";
        default: return "None";
    }
}

string hundreds(int num){
    return (bet1_9(num) + " " + "Hundred" + " ");
}

string bet1_99(int num){
    if (num<10)
        return (bet1_9(num) + " ");

    if (num>=10 && num <=19){
        return (bet10_19(num) + " ");
    }

    if (num%10==0)
        return (unique(num/10) + " ");

    return (unique(num/10) + " " + bet1_9(num%10) + " ");
}


string numberToWords(long long int num) {
    bool isEnd = false;
    bool isThousand = false;
    bool isMillion = false;
    bool isBillion = false;
    string result;
    if (num<0){
        result += "(Negative) ";
        num*=(-1);
    }
    if (num==0)
        return "Zero";
    long long int B = 0;
    long long int BB = 0;
    long long int M = 0;
    long long int MM = 0;
    long long int T = 0;
    long long int TT = 0;
    long long int H = 0;
    long long int TO = 0;

    B = num/100000000000;
    num-=B*100000000000;

    if (B!=0){
        result += hundreds(B);
        isBillion = true;
    }

    if ((num==0 && !isEnd) || (isBillion && (num/1000000000)==0)){
        result += (string("Billion") + string(" "));
        isEnd=true;
    }

    BB = num/1000000000;
    num-=BB*1000000000;

    if (BB!=0)
        result += (bet1_99(BB) + "Billion" + " ");

    if (num==0)
        isEnd=true;

    M = num/100000000;
    num-=M*100000000;

    if (M!=0){
        result += hundreds(M);
        isMillion = true;
    }

    if ((num==0 && !isEnd) || (isMillion && (num/1000000)==0)){
        result += (string("Million") + string(" "));
        isEnd=true;
    }

    MM = num/1000000;
    num-=MM*1000000;

    if (MM!=0)
        result += (bet1_99(MM) + "Million" + " ");

    if (num==0)
        isEnd=true;

    T = num/100000;
    num-=T*100000;

    if (T!=0){
        result += hundreds(T);
        isThousand=true;
    }

    if ((num==0 && !isEnd) || (isThousand && ((num/1000)==0)))
        result += (string("Thousand")+ string(" "));

    TT = num/1000;
    num-=TT*1000;

    if (TT!=0)
        result += (bet1_99(TT) + "Thousand" + " ");

    if (num==0)
        isEnd=true;

    H = num/100;
    num-=H*100;

    if (H!=0)
        result += hundreds(H);

    TO = num;
    num-=num;

    if (TO!=0)
        result += bet1_99(TO);

    result.resize(result.size() - 1);

    return result;
}

int main() {

    cout << numberToWords(999999999999) << endl;

    return 0;
}
