main: build/camera.o build/color.o build/hitRecord.o build/hittable_arr.o build/interval.o src/main.cpp build/ray.o build/sphere.o build/vec3d.o
	g++ -o main src/main.cpp build/camera.o build/color.o build/hitRecord.o build/hittable_arr.o build/interval.o build/ray.o build/sphere.o build/vec3d.o -g

build/camera.o: src/camera.cpp
	g++ -o build/camera.o src/camera.cpp -g -c

build/color.o: src/color.cpp
	g++ -o build/color.o src/color.cpp -g -c

build/hitRecord.o: src/hitRecord.cpp
	g++ -o build/hitRecord.o src/hitRecord.cpp -g -c

build/hittable_arr.o: src/hittable_arr.cpp
	g++ -o build/hittable_arr.o src/hittable_arr.cpp -g -c

build/interval.o: src/interval.cpp
	g++ -o build/interval.o src/interval.cpp -g -c

build/ray.o: src/ray.cpp
	g++ -o build/ray.o src/ray.cpp -g -c

build/sphere.o: src/sphere.cpp
	g++ -o build/sphere.o src/sphere.cpp -g -c

build/vec3d.o: src/vec3d.cpp
	g++ -o build/vec3d.o src/vec3d.cpp -g -c


clean:
	rm build/*.o
	rm main
	rm image.ppm

run:
	rm image.ppm
	./main >> image.ppm