FROM debian 
COPY Process1.cpp . 
COPY Process2.cpp . 
COPY create_files.sh .
RUN chmod ugo+x create_files.sh
RUN apt-get update 
RUN apt-get -y install gcc g++
RUN g++ -o Process1 Process1.cpp
RUN g++ -o Process2 Process2.cpp
RUN ./create_files.sh
CMD ./Process2 work_dir/ dest/; ls dest
