FROM ubuntu:latest
COPY . /opt
WORKDIR /opt
RUN apt-get update
RUN apt-get install -y g++
RUN apt-get install -y curl
RUN apt-get install -y libcurlpp-dev
RUN apt-get install -y libcurl4-openssl-dev
RUN apt-get install -y libcurl4-nss-dev
RUN apt-get install -y libcurl4-gnutls-dev
RUN g++ -std=c++11 -I/usr/include client.cpp -L/usr/lib -lcurlpp -lcurl -o client
CMD ["./client"]
EXPOSE 8000
