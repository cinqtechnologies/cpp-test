#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    int iLines;
    std::cin >> iLines;

    if(iLines <= 0)
    {
        std::cout << "There are no dirty bills.";

        return 0;
    }

    int iDirtyBills = 0;  // amount of dirty bills.

    for( int i = 0; i < iLines; ++i)
    {
        std::string strBillStatus; // bill status: 'clean' or 'dirty'.
        int         iAmountBills;  // amount bills of the given status.

        std::cin >> iAmountBills >> strBillStatus;

        if(strBillStatus == "dirty")
            iDirtyBills += iAmountBills;
    }

    if(iDirtyBills > 0)
        std::cout << "There are " << iDirtyBills << " dirty bills.";
    else
        std::cout << "There are no dirty bills.";

    return 0;
}
