agent: hotel_agent.o
	g++ hotel_agent.o -o hotel_agent

client: hotel_client.o alphabet.o
	g++ hotel_client.o alphabet.o -o hotel_client

hotel_agent.o:
	g++ -c hotel_agent.cpp

hotel_client.o:
	g++ -c hotel_client.cpp

alphabet.o:
	g++ -c ../lib/alphabet/alphabet.cpp

run_agent:
	./hotel_agent

run_client:
	./hotel_client

clean:
	rm -rf *.o hotel_agent hotel_client
