# Theory of Algorithms
## Project SHA512 2021
### Muhammad Noman Junaid
### G00351754@gmit.ie


SHA-512 is a hashing algorithm that performs a hashing function on some data given to it. Hashing algorithms are used in many things such as internet security, digital certificates and even blockchains.
Since hashing algorithms play such a vital role in digital security and cryptography, this is an easy-to-understand walkthrough, with some basic and simple maths along with some diagrams, for a hashing algorithm called SHA-512. It’s part of a group of hashing algorithms called SHA-2 which includes SHA-256 as well which is used in the bitcoin blockchain for hashing.

The hash  function then produces a fixed-size string that looks nothing like the original. These algorithms are designed to be one-way functions, meaning that once they’re transformed into their respective hash values, it’s virtually impossible to transform them back into the original data. A few algorithms of interest are SHA-1, SHA-2, and SHA-3, each of which was successively designed with increasingly stronger encryption in response to hacker attacks. SHA-0, for instance, is now obsolete due to the widely exposed vulnerabilities.[1]

## Hashing Algorithm — SHA-512
SHA-512 does its work in a few stages. These stages go as follows:
1. Input formatting
2. Hash buffer initialization
3. Message Processing
4. Output
Let’s look at these one-by-one.

### Input Formatting:
SHA-512 can’t actually hash a message input of any size, i.e. it has an input size limit. This limit is imposed by its very structure as you may see further on. The entire formatted mesage has basically three parts: the original message, padding bits, size of original message. And this should all have a combined size of a whole multiple of 1024 bits. This is because the formatted message will be processed as blocks of 1024 bits each, so each bock should have 1024 bits to work with.

### Original message / Padding bits
The input message is taken and some padding bits are appended to it in order to get it to the desired length. The bits that are used for padding are simply ‘0’ bits with a leading ‘1’ (100000…000). Also, according to the algorithm, padding needs to be done, even if it is by one bit. So a single padding bit would only be a ‘1’.
The total size should be equal to 128 bits short of a multiple of 1024 since the goal is to have the formatted message size as a multiple of 1024 bits (N x 1024).

### Message with padding / Padding size
After this, the size of the original message given to the algorithm is appended. This size value needs to be represented in 128 bits and is the only reason that the SHA-512 has a limitation for its input message.
Since the size of the original message needs to be represented in 128 bits and the largest number that can be represented using 128 bits is (2¹²⁸-1), the message size can be at most (2¹²⁸-1) bits; and also taking into consideration the necessary single padding bit, the maximum size for the original message would then be (2¹²⁸-2). Even though this limit exists, it doesn’t actually cause a problem since the actual limit is so high (2¹²⁸-2 = 340,282,366,920,938,463,463,374,607,431,768,211,454 bits).


### Message with padding and size
Now that the padding bits and the size of the message have been appended, we are left with the completely formatted input for the SHA-512 algorithm.

### Formatted Message / Hash buffer initialization:
The algorithm works in a way where it processes each block of 1024 bits from the message using the result from the previous block. Now, this poses a problem for the first 1024 bit block which can’t use the result from any previous processing. This problem can be solved by using a default value to be used for the first block in order to start off the process. (Have a look at the second-last diagram).
Since each intermediate result needs to be used in processing the next block, it needs to be stored somewhere for later use. This would be done by the hash buffer, this would also then hold the final hash digest of the entire processing phase of SHA-512 as the last of these ‘intermediate’ results.
So, the default values used for starting off the chain processing of each 1024 bit block are also stored into the hash buffer at the start of processing. The actual value used is of little consequence, but for those interested, the values used are obtained by taking the first 64 bits of the fractional parts of the square roots of the first 8 prime numbers (2,3,5,7,11,13,17,19). These values are called the Initial Vectors (IV).
Why 8 prime numbers instead of 9? Because the hash buffer actually consists of 8 subparts (registers) for storing them.


### Hash buffer and Initialization Vector values / Message Processing:
Message processing is done upon the formatted input by taking one block of 1024 bits at a time. The actual processing takes place by using two things: The 1024 bit block, and the result from the previous processing.
This part of the SHA-512 algorithm consists of several ‘Rounds’ and an addition operation.

### Rounds
The main part of the message processing phase may be considered to be the Rounds. Each round takes 3 things: one Word, the output of the previous Round, and a SHA-512 constant. The first Round doesn’t have a previous Round whose output it can use, so it uses the final output from the previous message processing phase for the previous block of 1024 bits. For the first Round of the first block (1024 bits) of the formatted input, the Initial Vector (IV) is used.
SHA-512 constants are predetermined values, each of whom is used for each Round in the message processing phase. Again, these aren’t very important, but for those interested, they are the first 64 bits from the fractional part of the cube roots of the first 80 prime numbers.Why 80? Because there are 80 Rounds and each of them needs one of these constants.
Once the Round function takes these 3 things, it processes them and gives an output of 512 bits. This is repeated for 80 Rounds. After the 80th Round, its output is simply added to the result of the previous message processing phase to get the final result for this iteration of message processing.

### Output:
After every block of 1024 bits goes through the message processing phase, i.e. the last iteration of the phase, we get the final 512 bit Hash value of our original message. So, the intermediate results are all used from each block for processing the next block. And when the final 1024 bit block has finished being processed, we have with us the final result of the SHA-512 algorithm for our original message.
Thus, we obtain the final hash value from our original message. The SHA-512 is part of a group of hashing algorithms that are very similar in how they work, called SHA-2. Algorithms such as SHA-256 and SHA-384 are a part of this group alongside SHA-512. SHA-256 is also used in the Bitcoin blockchain as the designated hash function.
That’s a brief overview of how the SHA-512 hashing algorithm works.I intend to go into further detail about what makes the hash functions practically irreversible (one-way) and how this is helpful for digital security. [2] [3]

## Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?

What happens in a real hash function is that hundreds of one-way operations take place sequentially and the results from earlier operations are used in later operations. So when you try to reverse it (and guess the two inputs in a later stage), the only way to tell if the numbers you are guessing are correct is to work all the way back through the hash algorithm.

If you start guessing numbers (in the later stages) wrong, you'll end up with an inconsistency in the earlier stages (like 2 + 2 = 53). And you can't solve it by trial and error, because there are simply too many combinations to guess (more than atoms in the known universe, etc) [4]

## Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?

In Theory its not imposible, that's a semi-decidable problem, so the answer is it can be done, if such a message exists for each SHA-512". Just brute force all possible strings, gradually increasing length, and you will get it.The largest SHA-512 message has a bit length of (2xx64) - 1. So try every message of bit length 0, every message of bit length 1, ..., every message of bit length (2xx64) - 1 and you're done.

## How difficult is it to find a hash digest beginning with at least twelve zeros?

First, we need to model SHA-512 as uniform random.

Start hashing random values.

In hex we have 4-bits

#### We would expect about 1 in 2^4 values to have a hash-value with 0x0 at the beginning.
#### We would expect about 1 in 2^8 values to have a hash-value with 0x00 at the beginning.
#### We would expect about 1 in 2^12 values to have a hash-value with 0x000 at the beginning.

#### We would expect about 1 in 248 values to have a hash-value with 12 hex zeroes at the beginning.
#### So we can say that we expect 2^512/2^4⋅k values will have leading k hex zeroes.

###
1B≈2^30.89  and to see 12 leading zeroes, the experiment must go to 2^48 and that needs still 2^18 more time. It is quite doable with a single CPU, though parallel processing is possible, too. Note that this is a Python experiment and took ~22 minutes for 1B.

For a CPU this may be hard to achieve since SHA-512, although a fast hash function, is still not a simple function to evaluate. If you have a GPU like GTX 1080 then you may reach 2^48 SHA-512 hashing around 36 hours and if you have GTX 3080 then you may need 18 hours.[5]

# References
1. [(https://brilliant.org/wiki/secure-hashing-algorithms/)]
2. [https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1]
3. [https://crypto.stackexchange.com/]
4. [https://crypto.stackexchange.com/questions/45377/why-cant-we-reverse-hashes]
5. [https://stackoverflow.com/]



