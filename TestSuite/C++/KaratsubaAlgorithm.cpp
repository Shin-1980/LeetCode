#include <iostream>

class Solution
{

    bool checkDigitPower2(long digit)
    {
        // 2,4,8
        int val = 2;

        while (digit >= val)
        {
            if (digit == val)
                return true;
            val *= 2;
        }

        return false;
    }

    std::string getSum(std::string v1, std::string v2)
    {
        std::string v12 = "";

        int res = 0;
        int carry = 0;

        for (int i = 0; i < std::max(v1.size(), v2.size()); i++)
        { 
            res = carry;

            if (i < v1.size())
                res += int(v1[i] - '0');
            if (i < v2.size())
                res += int(v2[i] - '0');

            carry = 0;
            if (res < 10)
            {
                v12 += std::to_string(res); // int(v1[i] - '0') + int(v2[i] - '0'));
            }
            else
            {
                carry = 1;
                res -= 10;
                v12 += std::to_string(res);
            }
        }

        if (carry > 0)
        {
            v12 += std::to_string(carry);
            carry = 0;
        }

        return v12;
    }

    std::string getRevStr(std::string st)
    {
        std::string rev = "";

        for (int i = st.size() - 1; i > -1; i--)
        {
            rev += st[i];
        }

        return rev;
    }


public:
    std::string karatsuba(std::string x, std::string y)
    {

        if (!checkDigitPower2(x.size()) || !checkDigitPower2(y.size())) {
            std::string errorStr = "The number of the digit is not a power of two.";
            return errorStr;
        }

        std::string revX = getRevStr(x);
        std::string revY = getRevStr(y);

        return getRevStr(this->karatsuba_exec(revX, revY));
    }

    std::string karatsuba_exec(std::string x, std::string y)
    {

        if (x.size() < 2 && y.size() < 2)
        {
            long xy = std::stoi(x) * std::stoi(y); // base case
            return getRevStr(std::to_string(xy));
        }

        int digit = std::max(x.size(), y.size());

        if (x.size() > y.size())
        {
            for (int i = 0; i < (x.size() - y.size()); i++)
                y += '0';
        }
        else if (x.size() < y.size())
        {
            for (int i = 0; i < (y.size() - x.size()); i++)
                x += '0';
        }

        int halfDigit = digit / 2;

        std::string x2 = x.substr(0, halfDigit); // x / mul;
        std::string x1 = x.substr(halfDigit);    // % mul;
        std::string y2 = y.substr(0, halfDigit); // / mul;
        std::string y1 = y.substr(halfDigit);    // % mul;

        std::string U = this->karatsuba_exec(x1, y1);
        std::string V = this->karatsuba_exec(x2, y2);
        std::string Z1 = this->karatsuba_exec(x1, y2);
        std::string Z2 = this->karatsuba_exec(x2, y1);
        std::string Z = getSum(Z1, Z2);

        std::string Ushift = "";
        if (U != "0")
        {
            for (int i = 0; i < digit; i++)
                Ushift += '0';
        }
        Ushift += U;

        std::string Zshift = "";
        if (Z != "0")
        {
            for (int i = 0; i < digit / 2; i++)
                Zshift += '0';
        }
        Zshift += Z;

        std::string res = this->getSum(this->getSum(Ushift, Zshift), V);

        return res;
    }

};

bool testCase1()
{

    std::string x = "45";
    std::string y = "12";
    std::string xy = "540";

    Solution *sl = new Solution();

    //std::cout << xy << std::endl << sl->karatsuba(x, y) << std::endl;

    if (xy == sl->karatsuba(x, y)) return true;
    return false;
}

bool testCase2()
{

    long xl = 4853;
    long yl = 1243;
    long xyl = xl * yl;

    std::string x = std::to_string(xl);
    std::string y = std::to_string(yl);
    std::string xy = std::to_string(xyl); //"540";

    Solution *sl = new Solution();

    //std::cout << xy << std::endl << sl->getRevStr(sl->karatsuba(x, y)) << std::endl;

    if (xy == sl->karatsuba(x, y)) return true;
    return false;
}

bool testCase3()
{

    std::string x = "2342339847238748234729834293823784723984284908423748273984723874";
    std::string y = "3447902384234234827482739847238472374289374290837293874298734882";

    Solution *sl = new Solution();

    //std::cout << sl->karatsuba(x, y) << std::endl;

    return true;
}

bool testCase4()
{

    long xl = 485;
    long yl = 123;
    long xyl = xl * yl;

    std::string x = std::to_string(xl);
    std::string y = std::to_string(yl);
    std::string xy = std::to_string(xyl); //"540";

    Solution *sl = new Solution();

    std::cout << sl->karatsuba(x, y) << std::endl;

    return true;
}


int main()
{

    int testCount = 0;

    testCount++;
    if (testCase1()) std::cout << "PATH" << testCount << std::endl;
    else std::cout << "ERROR" << testCount << std::endl;
    
    testCount++;
    if (testCase2())
        std::cout << "PATH" << testCount << std::endl;
    else
        std::cout << "ERROR" << testCount << std::endl;

    testCount++;
    if (testCase3()) std::cout << "PATH" << testCount << std::endl;
    else std::cout << "ERROR" << testCount << std::endl;

    testCount++;
    if (testCase4()) std::cout << "PATH" << testCount << std::endl;
    else std::cout << "ERROR" << testCount << std::endl;
}