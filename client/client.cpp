#include <cstdlib>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
        if(argc != 1)
        {
                std::cerr << "Example 04: Wrong number of arguments" << std::endl
                        << "Example 04: Usage: example04 url"
                        << std::endl;
                return EXIT_FAILURE;
        }
        string s1 = getenv("STREAMSERVICE1_SERVICE_HOST");
        string s2 = getenv("STREAMSERVICE1_SERVICE_PORT");
        string url="";
        url=url+"http://"+s1+":"+s2;
        try
        {
                curlpp::Cleanup cleaner;
                curlpp::Easy request;

                using namespace curlpp::Options;
                request.setOpt(Verbose(true));
                request.setOpt(Url(url));
                fstream file;
    file.open("streamdata.txt", ios::out);
    string line;

    // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();

    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();

    // Redirect cout to file
    cout.rdbuf(stream_buffer_file);
       std::stringstream result;

request.setOpt(cURLpp::Options::WriteStream(&result));

              request.perform();
             std::cout<<request ;
             file.close();
                std::string effURL;
                curlpp::infos::EffectiveUrl::get(request, effURL);
                std::cout << "Effective URL: " << effURL << std::endl;

                //other way to retreive URL
                std::cout << std::endl
                        << "Effective URL: "
                       << curlpp::infos::EffectiveUrl::get(request)
                        << std::endl;

                std::cout << "Response code: "
                        << curlpp::infos::ResponseCode::get(request)
                        << std::endl;

                std::cout << "SSL engines: "
                        << curlpp::infos::SslEngines::get(request)
                        << std::endl;

        }
        catch ( curlpp::LogicError & e ) {
                std::cout << e.what() << std::endl;
        }
        catch ( curlpp::RuntimeError & e ) {
                std::cout << e.what() << std::endl;
        }

        for (int i=0;;i++)
        {
                i--;
        }

        return 0;
}
