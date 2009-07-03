#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#include <iostream>

#include "string.hpp"


void Test()
{
    std::cout << std::endl << "StartWith----------------:" << std::endl;
    {
        std::string s = "   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        bool b1 = string::StartWith(s.c_str(), "JDK");
        bool b2 = string::StartWith(s.c_str(), "   dsa ");
        bool b3 = string::StartWith(s.c_str(), "   dsa j;fJDKOG:Jd   DK;s 'ghg    ");
        assert(!b1);
        assert(b2);
        assert(b3);
        
        std::wstring ws = L"   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        bool wb1 = string::StartWith(ws.c_str(), L"JDK");
        bool wb2 = string::StartWith(ws.c_str(), L"   dsa ");
        bool wb3 = string::StartWith(ws.c_str(), L"   dsa j;fJDKOG:Jd   DK;s 'ghg    ");
        assert(!wb1);
        assert(wb2);
        assert(wb3);
    }
    
    std::cout << std::endl << "EndWith----------------:" << std::endl;
    {
        std::string s = "   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        bool b1 = string::EndWith(s.c_str(), "'ghg");
        bool b2 = string::EndWith(s.c_str(), "ghg    ");
        bool b3 = string::EndWith(s.c_str(), ";fJDKOG:Jd   DK;s 'ghg    ");
        bool b4 = string::EndWith("", "a");
        assert(!b1);
        assert(b2);
        assert(b3);
        assert(!b4);
        
        std::wstring ws = L"   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        bool wb1 = string::EndWith(ws.c_str(), L"'ghg");
        bool wb2 = string::EndWith(ws.c_str(), L"ghg    ");
        bool wb3 = string::EndWith(ws.c_str(), L";fJDKOG:Jd   DK;s 'ghg    ");
        bool wb4 = string::EndWith(L"", L"a");
        assert(!wb1);
        assert(wb2);
        assert(wb3);
        assert(!wb4);
    }
    
    std::cout << std::endl << "ToUpper----------------:" << std::endl;
    {
        std::string s = "   JDKhg;'    ";
        s= string::ToUpper(s.c_str());
        std::string ss = string::ToUpper("adfds");
        assert(s == "   JDKHG;'    ");
        std::cout << s << std::endl;
        
        std::wstring ws = L"   JDKhg;'    ";
        ws = string::ToUpper(ws.c_str());
        assert(ws == L"   JDKHG;'    ");
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
    }
    
    std::cout << std::endl << "ToLower----------------:" << std::endl;
    {
        std::string s = "   JDKhg;'    ";
        s= string::ToLower(s.c_str());
        assert(s == "   jdkhg;'    ");
        std::cout << s << std::endl;
        
        std::wstring ws = L"   JDKhg;'    ";
        ws = string::ToLower(ws.c_str());
        assert(ws == L"   jdkhg;'    ");
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
    }
    
    std::cout << std::endl << "Replace----------------:" << std::endl;
    {
        std::string s = "   JDKhg;''    '";
        s= string::Replace(s.c_str(), "'", "''");
        assert(s == "   JDKhg;''''    ''");
        std::cout << s << std::endl;
        s= string::Replace(s.c_str(), "'", "|");
        assert(s == "   JDKhg;||||    ||");
        std::cout << s << std::endl;
        
        std::wstring ws = L"   JDKhg;''    '";
        ws = string::Replace(ws.c_str(), L"'", L"''");
        assert(ws == L"   JDKhg;''''    ''");
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
        ws = string::Replace(ws.c_str(), L"'", L"|");
        assert(ws == L"   JDKhg;||||    ||");
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
    }
    
    std::cout << std::endl << "TrimLeft----------------:" << std::endl;
    {
        std::string s = "   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        s= string::TrimLeft(s.c_str());
        std::cout << s << std::endl;
        assert(s == "dsa j;fJDKOG:Jd   DK;s 'ghg    ");
        std::cout << string::Replace(s.c_str(), " ", "-") << std::endl;
#ifndef __MINGW32__
        std::wstring ws = L"   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        ws = string::TrimLeft(ws.c_str());
        assert(ws == L"dsa j;fJDKOG:Jd   DK;s 'ghg    ");
        std::wcout << ws << std::endl;
        std::wcout << string::Replace(ws.c_str(), L" ", L"-") << std::endl;
#endif
    }
    
    std::cout << std::endl << "TrimRight----------------:" << std::endl;
    {
        std::string s = "   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        s= string::TrimRight(s.c_str());
        assert(s == "   dsa j;fJDKOG:Jd   DK;s 'ghg");
        std::cout << s << std::endl;
        std::cout << string::Replace(s.c_str(), " ", "-") << std::endl;
#ifndef __MINGW32__        
        std::wstring ws = L"   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        ws = string::TrimRight(ws.c_str());
        assert(ws == L"   dsa j;fJDKOG:Jd   DK;s 'ghg");
        std::wcout << ws << std::endl;
        std::wcout << string::Replace(ws.c_str(), L" ", L"-") << std::endl;
#endif
    }
    
    std::cout << std::endl << "Trim----------------:" << std::endl;
    {
        std::string s = "   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        s= string::Trim(s.c_str());
        assert(s == "dsa j;fJDKOG:Jd   DK;s 'ghg");
        std::cout << s << std::endl;
        std::cout << string::Replace(s.c_str(), " ", "-") << std::endl;
#ifndef __MINGW32__
        std::wstring ws = L"   dsa j;fJDKOG:Jd   DK;s 'ghg    ";
        ws  = string::Trim(ws.c_str());
        assert(ws == L"dsa j;fJDKOG:Jd   DK;s 'ghg");
        std::wcout << ws << std::endl;
        std::wcout << string::Replace(ws.c_str(), L" ", L"-") << std::endl;
#endif
    }
    
    std::cout << std::endl << "Join----------------:" << std::endl;
    {
        std::vector<std::string> vs;
        vs.push_back("a");
        vs.push_back("b");
        vs.push_back("c");
        std::string s = string::Join(vs.begin(), vs.end(), "|||");
        assert(s == "a|||b|||c");
        std::cout << s << std::endl;
        vs.clear();
        s= string::Join(vs.begin(), vs.end(), ",,,");
        assert(s == "");
        std::cout << s << std::endl;
        
        std::vector<std::wstring> vws;
        vws.push_back(L"a");
        vws.push_back(L"b");
        vws.push_back(L"c");
        std::wstring ws = string::Join(vws.begin(), vws.end(), L"|||");
        assert(ws == L"a|||b|||c");
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
        vws.clear();
        ws = string::Join(vws.begin(), vws.end(), L",,,");
        assert(ws == L"");
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
    }
    
    std::cout << std::endl << "Split----------------:" << std::endl;
    {
        std::string s = "a||b||c";
        std::vector<std::string> vs =  string::Split(s.c_str(), "||");
        assert(vs.size() == 3);
        assert(vs[0] == "a");
        assert(vs[1] == "b");
        assert(vs[2] == "c");
        std::cout << vs.size() << " "<< vs[0] << " " << vs[1] << " "<< vs[2] << std::endl;
        
        std::wstring ws = L"a||b||c";
        std::vector<std::wstring> vws =  string::Split(ws.c_str(), L"||");
        assert(vws.size() == 3);
        assert(vws[0] == L"a");
        assert(vws[1] == L"b");
        assert(vws[2] == L"c");
#ifndef __MINGW32__
        std::wcout << vws.size() << L" "<< vws[0] << L" " << vws[1] << L" "<< vws[2] << std::endl;
#endif
    }
    
    std::cout << std::endl << "EqualsIgnoreCase----------------:" << std::endl;
    {
        std::cout << "EqualsIgnoreCase start" << std::endl;
        assert(string::EqualsIgnoreCase("aaDddf", "AAddDf"));
        assert(string::EqualsIgnoreCase(L"aaDddf", L"AAddDf"));
        std::cout << "EqualsIgnoreCase end" << std::endl;
    }
    
    std::cout << std::endl << "Format----------------:" << std::endl;
    {
        std::string s = string::Format("%d", 4);
        std::cout << s << std::endl;
        assert(s == "4");
        s= string::Format("%d,%s", 4, "dafkd");
        std::cout << s << std::endl;
        assert(s == "4,dafkd");
        s= string::Format<2000>("%d,%s", 4, "dafkd");
        std::cout << s << std::endl;
        assert(s == "4,dafkd");
        try
        {
            s = string::Format<2>("%d,%s", 4, "dafkd");
//            assert(s == "4,dafkd");
            std::cout << s << std::endl;
        }
        catch (const std::length_error& e)
        {
            std::cout << e.what() << std::endl;
        }
        
        
        std::wstring ws = string::Format(L"%d", 4);
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
        assert(ws == L"4");
#ifdef _WIN32
        ws = string::Format(L"%d,%s", 4, L"dafkd");
#else
        ws = string::Format(L"%d,%s", 4, "dafkd");
#endif
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
        assert(ws == L"4,dafkd");
#ifdef _WIN32
        ws = string::Format<2000>(L"%d,%s", 4, L"dafkd");
#else
        ws = string::Format<2000>(L"%d,%S", 4, L"dafkd");
#endif
#ifndef __MINGW32__
        std::wcout << ws << std::endl;
#endif
        assert(ws == L"4,dafkd");
        try
        {
            ws = string::Format<3>(L"%d,%s", 4, L"dafkd");
//            assert(ws == L"4,dafkd");
#ifndef __MINGW32__
            std::wcout << ws << std::endl;
#endif
        }
        catch (const std::length_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << std::endl << "GetLastPath----------------:" << std::endl;
    {
        std::string s = "/tmp/scratch.tiff";
        std::string s1 = string::GetLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch.tiff");
        s = "/tmp/scratch";
        s1 = string::GetLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch");
        s = "/tmp/";
        s1 = string::GetLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tmp");
        s = "scratch";
        s1 = string::GetLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch");
        s = "/";
        s1 = string::GetLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/");
        s = "\\tmp\\scratch.tiff";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch.tiff");
        s = "\\tmp\\scratch";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch");
        s = "\\tmp\\";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tmp");
        s = "scratch";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch");
        s = "\\";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\");
        s = "c:\\aaa\\bbb";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "bbb");
        s = "c:\\";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "c:");
        s = "c:";
        s1 = string::GetLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "c:");
    }
#ifndef __MINGW32__
    {
        std::wstring s = L"/tmp/scratch.tiff";
        std::wstring s1 = string::GetLastPath(s.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch.tiff");
        s = L"/tmp/scratch";
        s1 = string::GetLastPath(s.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch");
        s = L"/tmp/";
        s1 = string::GetLastPath(s.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tmp");
        s = L"scratch";
        s1 = string::GetLastPath(s.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch");
        s = L"/";
        s1 = string::GetLastPath(s.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/");
        s = L"\\tmp\\scratch.tiff";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch.tiff");
        s = L"\\tmp\\scratch";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch");
        s = L"\\tmp\\";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tmp");
        s = L"scratch";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch");
        s = L"\\";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"\\");
        s = L"c:\\aaa\\bbb";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"bbb");
        s = L"c:\\";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"c:");
        s = L"c:";
        s1 = string::GetLastPath(s.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"c:");
    }
#endif

    std::cout << std::endl << "AppendPath----------------:" << std::endl;
    {
        std::string name = "scratch.tiff";
        std::string s = "/tmp";
        std::string s1 = string::AppendPath(s.c_str(), name.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp/scratch.tiff");
        s = "/tmp/";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp/scratch.tiff");
        s = "/";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/scratch.tiff");
        s = "";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch.tiff");
        s = "tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tmp/scratch.tiff");
        s = "\\tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\tmp\\scratch.tiff");
        s = "\\tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\tmp\\scratch.tiff");
        s = "\\";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\scratch.tiff");
        s = "";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch.tiff");
        s = "tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tmp\\scratch.tiff");
        s = "c:\\aaa\\bbb";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "c:\\aaa\\bbb\\scratch.tiff");
        s = "c:\\";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "c:\\scratch.tiff");
        s = "c:";
        s1 = string::AppendPath(s.c_str(), name.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "c:\\scratch.tiff");
    }
#ifndef __MINGW32__
    {
        std::wstring name = L"scratch.tiff";
        std::wstring s = L"/tmp";
        std::wstring s1 = string::AppendPath(s.c_str(), name.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/tmp/scratch.tiff");
        s = L"/tmp/";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/tmp/scratch.tiff");
        s = L"/";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/scratch.tiff");
        s = L"";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch.tiff");
        s = L"tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"/");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tmp/scratch.tiff");
        s = L"\\tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"\\tmp\\scratch.tiff");
        s = L"\\tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"\\tmp\\scratch.tiff");
        s = L"\\";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"\\scratch.tiff");
        s = L"";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch.tiff");
        s = L"tmp";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tmp\\scratch.tiff");
        s = L"c:\\aaa\\bbb";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"c:\\aaa\\bbb\\scratch.tiff");
        s = L"c:\\";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"c:\\scratch.tiff");
        s = L"c:";
        s1 = string::AppendPath(s.c_str(), name.c_str(), L"\\");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"c:\\scratch.tiff");
    }
#endif

    std::cout << std::endl << "DeleteLastPath----------------:" << std::endl;
    {
        std::string s = "/tmp/scratch.tiff";
        std::string s1 = string::DeleteLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp");
        s = "/tmp/lock/";
        s1 = string::DeleteLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp");
        s = "/tmp/";
        s1 = string::DeleteLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/");
        s = "/tmp";
        s1 = string::DeleteLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/");
        s = "/";
        s1 = string::DeleteLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/");
        s = "scratch.tiff";
        s1 = string::DeleteLastPath(s.c_str(), "/");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
        s = "\\tmp\\scratch.tiff";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\tmp");
        s = "\\tmp\\lock\\";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\tmp");
        s = "\\tmp\\";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\");
        s = "\\tmp";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\");
        s = "\\";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "\\");
        s = "scratch.tiff";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
        s = "c:\\aaa\\bbb";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "c:\\aaa");
        s = "c:\\";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
        s = "c:";
        s1 = string::DeleteLastPath(s.c_str(), "\\");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
    }
#ifndef __MINGW32__
    {
        std::wstring ws = L"/tmp/scratch.tiff";
        std::wstring ws1 = string::DeleteLastPath(ws.c_str(), L"/");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"/tmp");
        ws = L"/tmp/lock/";
        ws1 = string::DeleteLastPath(ws.c_str(), L"/");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"/tmp");
        ws = L"/tmp/";
        ws1 = string::DeleteLastPath(ws.c_str(), L"/");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"/");
        ws = L"/tmp";
        ws1 = string::DeleteLastPath(ws.c_str(), L"/");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"/");
        ws = L"/";
        ws1 = string::DeleteLastPath(ws.c_str(), L"/");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"/");
        ws = L"scratch.tiff";
        ws1 = string::DeleteLastPath(ws.c_str(), L"/");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"");
        ws = L"\\tmp\\scratch.tiff";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"\\tmp");
        ws = L"\\tmp\\lock\\";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"\\tmp");
        ws = L"\\tmp\\";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"\\");
        ws = L"\\tmp";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"\\");
        ws = L"\\";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"\\");
        ws = L"scratch.tiff";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"");
        ws = L"c:\\aaa\\bbb";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"c:\\aaa");
        ws = L"c:\\";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"");
        ws = L"c:";
        ws1 = string::DeleteLastPath(ws.c_str(), L"\\");
        std::wcout << ws << L" --> " << ws1 << std::endl;
        assert(ws1 == L"");
    }
#endif

    std::cout << std::endl << "GetPathExtension----------------:" << std::endl;
    {
        std::string s = "/tmp/scratch.tiff";
        std::string s1 = string::GetPathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tiff");
        s = "/tmp/scratch";
        s1 = string::GetPathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
        s = "/tmp/";
        s1 = string::GetPathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
        s = "/scratch..tiff";
        s1 = string::GetPathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tiff");
        s = "/scratch.tiff/tmp";
        s1 = string::GetPathExtension(s.c_str(), ".");
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tiff/tmp");
#ifdef _WIN32
        s = "\\scratch.tiff\\tmp";
#else
        s = "/scratch.tiff/tmp";
#endif
        s1 = string::GetPathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
    }
#ifndef __MINGW32__
    {
        std::wstring s = L"/tmp/scratch.tiff";
        std::wstring s1 = string::GetPathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tiff");
        s = L"/tmp/scratch";
        s1 = string::GetPathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"");
        s = L"/tmp/";
        s1 = string::GetPathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"");
        s = L"/scratch..tiff";
        s1 = string::GetPathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tiff");
        s = L"/scratch.tiff/tmp";
        s1 = string::GetPathExtension(s.c_str(), L".");
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tiff/tmp");
#ifdef _WIN32
        s = L"\\scratch.tiff\\tmp";
#else
        s = L"/scratch.tiff/tmp";
#endif
        s1 = string::GetPathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"");
    }
#endif

    std::cout << std::endl << "AppendPathExtension----------------:" << std::endl;
    {
        std::string ext = "tiff";
        std::string s = "/tmp/scratch.old";
        std::string s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp/scratch.old.tiff");
        s = "/tmp/scratch.";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp/scratch..tiff");
        s = "/tmp/";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp/.tiff");
        s = "scratch";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch.tiff");
        s = "c:\\a";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "c:\\a.tiff");
    }
#ifndef __MINGW32__
    {
        std::wstring ext = L"tiff";
        std::wstring s = L"/tmp/scratch.old";
        std::wstring s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/tmp/scratch.old.tiff");
        s = L"/tmp/scratch.";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/tmp/scratch..tiff");
        s = L"/tmp/";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/tmp/.tiff");
        s = L"scratch";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch.tiff");
        s = L"c:\\a";
        s1 = string::AppendPathExtension(s.c_str(), ext.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"c:\\a.tiff");
    }
#endif

    std::cout << std::endl << "DeletePathExtension----------------:" << std::endl;
    {
        std::string s = "/tmp/scratch.tiff";
        std::string s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp/scratch");
        s = "/tmp/";
        s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/tmp/");
        s = "scratch.bundle/";
        s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch");
        s = "scratch..tiff";
        s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch.");
        s = ".tiff";
        s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "");
        s = "/";
        s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "/");
        s = "scratch...";
        s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "scratch..");
        s = "tmp.bundle/scrtch";
        s1 = string::DeletePathExtension(s.c_str());
        std::cout << s << " --> " << s1 << std::endl;
        assert(s1 == "tmp");
    }
#ifndef __MINGW32__
    {
        std::wstring s = L"/tmp/scratch.tiff";
        std::wstring s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/tmp/scratch");
        s = L"/tmp/";
        s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/tmp/");
        s = L"scratch.bundle/";
        s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch");
        s = L"scratch..tiff";
        s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch.");
        s = L".tiff";
        s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"");
        s = L"/";
        s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"/");
        s = L"scratch...";
        s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"scratch..");
        s = L"tmp.bundle/scrtch";
        s1 = string::DeletePathExtension(s.c_str());
        std::wcout << s << L" --> " << s1 << std::endl;
        assert(s1 == L"tmp");
    }
#endif
}
        
        
int main()
{
    Test();
    return 0;
}