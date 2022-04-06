// HelloBenchmark.cpp : Defines the entry point for the application.
//


#include <vector>
#include <limits>
#include <benchmark/benchmark.h>

std::vector<int> rng(int begin, int end, int count)
{
	std::vector<int> v;
	v.reserve(count);
	for (int i = 0; i < count; i++)
		v.push_back((std::rand() % end) + begin);

	return v;
}


static void BM_StringCreation(benchmark::State& state) 
{
#if 0
	while (state.KeepRunning())
	{
		// code to be benchmarked
	}
#endif

	for (auto _ : state)
		std::string empty_string;
}


// Define another benchmark
static void BM_StringCopy(benchmark::State& state) 
{
	std::string x = "hello";
	for (auto _ : state)
		std::string copy(x);
}

void cacheBench(benchmark::State& state)
{
	int bytes = 1 << state.range(0);
	int count = int(bytes / sizeof(int) / 2);

	static int lastCount = 0;
	std::vector<int> v;
	std::vector<int> indices;

	if (count != lastCount)
	
	lastCount = count;

	// create a vector of random numbers:
	v.reserve(count);
	for (auto i : rng(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), count))
	{
		v.push_back(i);
	}

	// Create a vector of random indicies:
	indices.reserve(count);
	for (auto i : rng(0, count, count))
	{
		indices.push_back(i);
	}
	

	// Perform the benchmark loop:
	//for (auto _ : state)
	while(state.KeepRunning())
	{
		long sum = 0;
		for (int i : indices)
		{
			sum += v[i];
		}
		benchmark::DoNotOptimize(sum);
		benchmark::ClobberMemory();
	}

	// Manage benchmark state:
	uint64_t iterations = uint64_t(state.iterations());
	uint64_t bytesProcessed = iterations * uint64_t(bytes);
	state.SetBytesProcessed(bytesProcessed);
	// Insert a custom label:
	state.SetLabel(std::to_string(bytes / 1024) + " kb " + std::to_string(indices[1024]));


}

static void DoSetup(const benchmark::State& state) 
{	
}

static void DoTeardown(const benchmark::State& state) 
{
}

// Register the functions as a benchmarks
#if 0
BENCHMARK(BM_StringCreation);
BENCHMARK(BM_StringCopy);
#endif

BENCHMARK(cacheBench)
->DenseRange(13, 27)
->ReportAggregatesOnly(true)
->Threads(1)
->Setup(DoSetup)
->Teardown(DoTeardown);



BENCHMARK_MAIN();


