g++ -std=c++17 randomize.cpp -o rand
for index in {1..40000}
do
	./rand
done
