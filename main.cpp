#include <iostream>
#include <memory>
#include <string>
#include "AbstractSportProduct.h"
#include <regex>
#include <cwctype>

void test_factory_pattern()
{

    //定义工厂类对象和产品类对象
    std::wcout.imbue(std::locale(""));
    std::wcout << std::wstring(L"(---工厂模式测试：---)") << std::endl;
    std::unique_ptr<AbstractFactory> factory;
    std::unique_ptr<AbstractSportProduct> product;

    factory = std::make_unique<BasketballFactory>();
    product.reset(factory->get_sport_product());

    factory = std::make_unique<FootballFactory>();
    product.reset(factory->get_sport_product());

    factory = std::make_unique<volleyballFactory>();
    product.reset(factory->get_sport_product());

}
//去除空格的方法
const std::wstring __Y(L"\"");
const std::wstring __CYF(L"“");
const std::wstring __CYE(L"”");
const std::wstring __P(L"-");
const std::wstring __CP(L"—");
const std::wstring __M(L":");
const std::wstring __CM(L"：");
const std::wstring __KL(L"(");
const std::wstring __KR(L")");
const std::wstring __CKL(L"（");
const std::wstring __CKR(L"）");
const std::wstring __CSL(L"《");
const std::wstring __CSR(L"》");
std::wstring process_blank_char(std::wstring origin_str)
{

    std::wcout.imbue(std::locale(""));
    std::wstring result;
    wchar_t to_wstring[2] = {0};
    for(int i = 0; i < origin_str.size(); ++i )
    {
        to_wstring[1] = L'\0';
        to_wstring[0] = origin_str.at(i);
        auto wstr_one = std::wstring(to_wstring);
        //如果当前字符是那些字符，就把前面的空格去掉
        if( wstr_one == __Y || wstr_one == __CYF || wstr_one == __CYE || wstr_one == __P || wstr_one == __CP ||
        wstr_one == __M|| wstr_one == __CM|| wstr_one == __KL|| wstr_one == __KR|| wstr_one == __CKL|| wstr_one ==
        __CKR|| wstr_one == __CSL|| wstr_one == __CSR)
        {
            while (result.at(result.size()-1) == L'\t' || result.at(result.size()-1) == L' ' || result.at(result.size()-1) == L'\r' || result.at(result.size()-1) == L'\n')
            {
                result.pop_back();
            }
        }
        if(origin_str.at(i) == L'\t' || origin_str.at(i) == L' '|| origin_str.at(i) == L'\r'|| origin_str.at(i) ==
                                                                                               L'\n')
        {
            to_wstring[0] = result.at(result.size()-1);
            to_wstring[1] = L'\0';
            auto last_one = std::wstring (to_wstring);
            if( last_one== __Y || last_one== __CYF || last_one== __CYE || last_one== __P || last_one== __CP ||
                last_one== __M|| last_one== __CM|| last_one== __KL|| last_one== __KR|| last_one==
                                                                                       __CKL|| last_one== __CKR|| last_one== __CSL|| last_one== __CSR)
            {
                continue;
            }
        }
        result += origin_str.at(i);
    }
    return result;
    
}
void process_time_pair(std::wstring str)
{
    std::wcout.imbue(std::locale(""));
    std::wregex reg(L"[（(](\\d{1,4}[-—]{1,2}\\d{1,4})[)）]");
    std::wsmatch result;
   if(std::regex_search(str,result,reg))
   {

       std::wcout << result.str(0) << std::endl;
       std::wcout << result.str(1)<< std::endl;
   }
   else
   {
       std::wcout << L"oh,正则失败！" << std::endl;
   }

}

int test_symbol_check()
{
//    test_factory_pattern();
    std::wcout.imbue(std::locale(""));
    std::wcout << L"英文引号前后不能有空白，测试用例为：";
    std::wstring test_str_Y(L"ni \t\n\r\t \"\t\r\n  hao     \"    ");
    std::wcout << test_str_Y << std::endl;
    std::wcout << process_blank_char(test_str_Y) << std::endl;
    std::wcout << L"中文引号前后不能有空白，测试用例为：";
    std::wstring test_str_CY(L"这是 \t\r\n“ 你大爷 ”\t\r\n ");
    std::wcout << test_str_CY << std::endl;
    std::wcout << process_blank_char(test_str_CY) << std::endl;
    std::wcout << L"书名号前后不能有空白，测试用例为：";
    std::wstring test_str_S(L"这是  \n\t\r\t\r《  红楼梦  \t\t\n》 \t啊");
    std::wcout << test_str_S << std::endl;
    std::wcout << process_blank_char(test_str_S) << std::endl;

    std::wstring test_str(L"热烈 — \r\n\t\n— 庆祝中国共产党成立100周年！");
    std::wcout << process_blank_char(test_str) << std::endl;
    std::wstring test_str_reg(L"热烈庆祝中国共产党--成立周年！");
    process_time_pair(test_str_reg);
    setlocale(LC_ALL,"");

    std::wstring test_iswalpha(L"12345abcde你好啊！");
    for(auto &i:test_iswalpha)
    {
        std::wcout << i << L"\t" << std::iswalpha(i) << std::endl;
        std::wcout << i << L"\t" << std::islower(i) << std::endl;
    }


    return 0;
}
int c[20] = {0}, n=20, cnt=0;
void print()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(j == c[i])
            {
                std::cout<<"1 ";
            }
            else
            {
                std::cout<<"0 ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void search(int r){
    if(r == n)
    {
        print();
        ++cnt;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        c[r] = i;
        int ok = 1;
        for(int j=0; j<r; ++j)
        {
            if(c[r]==c[j] || r-j==c[r]-c[j] || r-j==c[j]-c[r])
            {
                ok = 0;
                break;
            }

        }
        if(ok)
        {
            search(r+1);
        }
    }
}
int main()
{
    search(0);
    std::cout << cnt << std::endl;
    return 0;
}