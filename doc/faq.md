Frequently Asked Questions {#faq}
=========

- [Why is the speed-up of my code not as expected?](#faq-speed)

  how can i use intrinsic XXX? We map the itnrinsic wherer is makes sense semaentaically
  and if it does not, you may call it your self, however this willll not be portable
 
  i try to use comaprison operator and failed to compile - check types - types
  should be equal, use auto or as_logical_t 
  vectorized comaprison and reduction comarpsion

   
  My code seg faulted? - memory aligned?
  my code is much faster than expected - cache hot

\anchor faq-speed Speed

  There are several factors which can reduce the speed-up obtained using **Boost.SIMD**.
  - Have you enabled compiler optimizations? 
    You must enable all compiler optimizations as well as defining the `NDEBUG` flag

    <table align=center width=25% class="table-striped table-bordered">
    <tr><th>Compiler                <th>Flag
    <tr><td>g++                     <td>-O3
    <tr><td>clang++                 <td>-O3
    <tr><td>Visual Studio           <td>Enable Release mode
    </table>

  - Have you compiled in 64bit mode?
    There is significant performance increase on architectures supporting
    64 bit binaries.
   
  - Is you algorithm memory bound?
    Computational problems can often be classed as either compute-bound or
    memory-bound. Memory bound problems reachthe limits of the system
    bandwidth transfering data between the memory and the processor, while
    compute-bound problems are limited by the processor's calculation ability.

    Processors have often several hierarchies of caches. The time taken to
    transfer data from the cache to a register varies depending on the cache.
    When the required data is not in the cache, it is referred to as a cache
    miss. Cache-misses are very expensive. Data is transfered from memory
    to the cache in cache-lines sized chunks. On modern x86 machines, a cache-line is 
    64 bytes or twice the size of an AVX register. It is therefore highly
    advantageous to use all data loaded into cache.

    The following loop is clearly memory bound as all of the time is spent
    loading and storing the data. The cost of the computation is negligible
    compared to that of the memory accesses.

    @snippet memorybound.cpp memory-memory
    
    The following loop is compute-bound. The cost of ca
    @snippet memorybound.cpp memory-compute


aligned memory
- memory bound
  64 bit mode
  bad algorithm - is it vectorizable enough? 
  cache issues
  input size big enough
  how to measure performance
  auto vetcorizer
  sometimes choice between accuracy and speed, see decorators for more
  complex functions
  architecture issues - double on altivec, integers on AVX
  compilers being crap
