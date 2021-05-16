# Channel-Coding-Architecture-for-5G-wireless-Communications-using-High-Level-Synthesis

In today’s fast changing world, the demand for Mobile Internet is increasing day by day. The fourth generation (4G) systems are now in use worldwide. The present day’s 4G LTE has some challenges left such as higher data rates and spectral efficiency due to the tremendous increase in the number of mobile internet users. This led us to a situation of replacing Turbo codes of 4G systems with a channel code that promises higher throughputs. Ever since, the 3GPP had accepted the LDPC codes as a channel coding scheme for 5G wireless communications, a lot of research is going on to optimise the decoder. In 5G, LDPC codes and polar codes are used for error correction for the data channel and control channel respectively. The prime objectives of fifth generation systems are higher data rate, higher spectral efficiency, higher throughput, higher bandwidth, and higher energy efficiency that too at lower latency. Channel coding plays a vital role in any wireless communication system. Our project presents a novel efficient high-throughput encoder and decoder for Low Density Parity Check codes for 5th generation wireless Communications. This work proposes strategies to achieve high-throughput channel coding architecture
for LDPC codes. The proposed design achieves peak throughputs in lower latencies, which meets the throughput and latency requirement for the 5G NR standard. The proposed design is first implemented in Matlab. Verified and then implemented in HLS. 
<br>
Tech Stack: Matlab 2020.a, Vivado HLS 2020.1 
<br>
<h1>Approach</h1>
<p> <b> Channel Coding Technique : </b> LDPC encoding and decoding </p>
<p> <b> Encoding Algorithm : </b> Using Double Diagonal Structure of base matrix </p>
<p> <b> Decoding ALgorithm : </b> Min-Sum BP using Layered Decoding </p>
<p> <b> Modulation Technique : </b> BPSK</p>
<p> <b> Channel Noise </b> AWGN </p>
<p> <b> HLS Transformation Techniques : </b> Pipelining, parallel processing, Loop Unrolling, Array Partitioning </p>

<h1>Achieved Results </h1>
<p> <b> Tagret Device : </b> Kintex-7 484G family </p>
<p> <b> Throughput : </b> 2.113 GB/s</p>
<p> <b> Latency : </b> 19.8 &micro s </p>

<h1>References</h1>
<ul>
<li> <a href="https://www.hindawi.com/journals/ijrc/2017/3689308/">FPGA-Based Channel Coding Architectures for 5G Wireless Using High-Level Synthesis</a> </li>
<li> <a href="https://dl.acm.org/doi/10.1145/3290420.3290441">Optimization of FPGA-based LDPC decoder using high-level synthesis</a> </li>
<li> <a href="https://ieeexplore.ieee.org/abstract/document/9148457">Adaptive Modulation and Coding Technology in 5G System</a> </li>
</ul>
