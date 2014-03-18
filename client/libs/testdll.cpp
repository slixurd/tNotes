

#include <windows.h>

#include <iostream.h>


int main(int argc, char *argv[])

{
    typedef std::string (*DLLWITHLIB)(std::string);   
    DLLWITHLIB testFunc = NULL;
    std::string testStr, in;
    if (argc == 1)
    {
      in = "hello\n====\n## hello world ##\n* foo\n* bar\n *foobar\n";
    } else {
      in = argv[1];
    }
    HINSTANCE hinst=::LoadLibrary("markdown2html.dll"); 
    if (NULL == hinst)
    {

       cout<<"markdown2html.ll not found!"<<endl;
       return 0;
    }
    
    testFunc = (DLLWITHLIB)GetProcAddress(hinst, "markdown2HTML");
    
    testStr = (*testFunc)(in);
    cout<<testStr<<endl;
    system("pause");

    return 0;

}
