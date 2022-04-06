# HelloGoogleBenchmark
This is a bit of basic experimenting with the google benchmark library.  Note that this is a cmake project so that it is easy to build on the dependency of the basic google benchmark library which is also cmake based.  This project assumes that you have already "cmake installed" google benchmark as release build.

# Building for visual studio:
<code>

C:\Users\steph\source\repos\HelloGoogleBenchmark> mkdir build

C:\Users\steph\source\repos\HelloGoogleBenchmark> cd build

C:\Users\steph\source\repos\HelloGoogleBenchmark\build> cmake -G "Visual Studio 17 2022" -Ax64 ..

</code>