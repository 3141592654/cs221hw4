    Question 2
Algorithm has O(n) complexity as a function of npoints. NOTE: Github's previewer isn't displaying the table properly. Opening the file itself should fix that.

npoints		estimate	runtime
10		3.12		0.004s
100		3.1412		0.005s
1000		3.14154		0.005s
10000		3.14159		0.005s

The fact that the real runtime does not much change would indicate that the algorithm in fact has O(1) complexity. However larger values of npoints indicate that this is not the case.

10^5		3.14159		0.006s
10^6		3.14159		0.025s
10^7		3.14159		0.207s
10^8		3.14159		2.018s

Note how from 10^6 on it increases by a factor of about 10 each time. npoints is increasing by about 10, so runtime is roughly linear as a function of npoints. It also looks like there is a constant factor of 0.005s or so.

    Question 3
npoints		estimate	runtime
10		3.12		0.004s
100		3.1412		0.004s
1000		3.14154		0.004s

Everything stayed the same but this is an artifact of the relatively low input size. For larger inputs (the longest compilation that I had the stomach to wait through was for npoints=6*10^5), the estimate stays the same, the runtime is constant, and the compilation takes longer. Why this happens... Calculating gridpi of some fixed number gives a deterministic result. So when the compiler goes to compile constexpr double d = gridpi(somenumber); it can implement that by simply computing the result and saying d=result. This isn't necessarily a good idea so you have to declare both d and gridpi constexpr for the compiler to do this. The constexpr version has constant runtime since printing the result does not take much computing power. Conversely it takes longer to compile since the compiler has to compute the result of the function. (Curiously, I note it takes the compiler longer to compile using constexpr than it takes to compile and run the program without constexpr).

