# Overview
In this repository you will find a C++ class implimentation of a [maximum length sequence (MLS)](http://www.kempacoustics.com/thesis/node83.html) generator. MLS singals have a flat spectturm which make them useful for extractign impulse responses from LTI systems.
For non-determinsitic random singals, you can have the generator seed the process with your local device's entropy source (std::random_device). Alternatively, you can have the generator seed with a CSPRNG using an AES-256-CTR cipher.


![An example MLS generator where the next value of register a3 in a feedback shift register of length 4 is determined by the modulo-2 sum of a0 and a1.(wikipedia)](https://raw.githubusercontent.com/ymirsky/MLSgen/master/MLS_shiftregisters_L4_wikipedia.png)


# Installation
Provided in the repo is the mls class, and a demo Qt project which can be compiled using qmake. To install qmake in Ubuntu, run the following in the terminal:

```
sudo apt-get install qt4-qmake
sudo apt-get install libqt4-dev
```

To compile the provided project, run the following from the source directory:

```
qmake MLSgen.pro
make
```

To execute the compiled demo, run (linux):
```
./MLSgen
```
you should see an output similar to:

![](https://raw.githubusercontent.com/ymirsky/MLSgen/master/sample_output.png)


# Usage

You can use the mls class in your own projects. To do so, you must copy all of the provided source files (except main.cpp) and include mls.h
The following are some example usages of the class:
```
\\Set the MLS parameter
int m = 6; //(63 bits per sequence : L=2^m-1)

\\Example with AES-256-CTR as seed
mls mls_aes(6,true);
for(int i = 0; i < 3; i++)
vector<bool> mls_seq = mls_aes.get_seq();
for(int b = 0; b < mls_seq.size(); b++)
	cout<<mls_seq[b]<<" ";
cout<<endl;

\\Example with device entropy source as seed
mls mls_rnd(6);
vector<bool> mls_seq = mls_rnd.get_seq();
for(int b = 0; b < mls_seq.size(); b++)
	cout<<mls_seq[b]<<" ";
cout<<endl;
```

Things to note:
* AES mode is seeded with random_device, so we assume that the API provides a truly random initial seed. 
* To avoid repitions, the sequence size L (controlled with parameter m) must be relativly large (e.g., m=10). 

# Citation
I you use this tool, please cite our research paper:

*Mirsky Y, Kalbo N, Elovici Y, Shabtai A. Vesper: Using Echo-Analysis to Detect Man-in-the-Middle Attacks in LANs. IEEE Transactions on Information Forensics and Security. 2018 Nov 23.*

# License
This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details

Yisroel Mirsky
yisroel@post.bgu.ac.il
