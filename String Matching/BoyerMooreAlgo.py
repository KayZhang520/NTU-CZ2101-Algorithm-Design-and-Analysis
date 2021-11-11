 # Python3 Program for Bad Character Heuristic
# of Boyer Moore String Matching Algorithm

NO_OF_CHARS = 256

def badCharHeuristic(string, size):
	'''
	The preprocessing function for
	Boyer Moore's bad character heuristic
	'''

	# Initialize all occurrence as -1
	badChar = [-1]*NO_OF_CHARS

	# Fill the actual value of last occurrence
	for i in range(size):
		badChar[ord(string[i])] = i;

	# return initialized list
	return badChar

def search(txt, pat):
	'''
	A pattern searching function that uses Bad Character
	Heuristic of Boyer Moore Algorithm
	'''
	m = len(pat)
	n = len(txt)

	# create the bad character list by calling sub function
	badChar = badCharHeuristic(pat, m)

	# s is shift of the pattern with respect to text
	s = 0
	while(s <= n-m): 
		j = m-1

		# use j to check if pattern exist at txt[s]
		while j>=0 and pat[j] == txt[s+j]:
			j -= 1

		# if matched j becomes -1
		if j==-1:
			print("Pattern occur at shift = {}".format(s))

			'''
				Shift the pattern so that the next character in text
					aligns with the last occurrence of it in pattern.
				The condition s+m < n is necessary for the case when
				pattern occurs at the end of text
			'''
			s += (m-badChar[ord(txt[s+m])] if s+m<n else 1)
		else:
			'''
			Shift the pattern so that the bad character in text
			aligns with the last occurrence of it in pattern. The
			max function is used to make sure that we get a positive
			shift. We may get a negative shift if the last occurrence
			of bad character in pattern is on the right side of the
			current character.
			'''
			s += max(1, j-badChar[ord(txt[s+j])])


# Driver program to test a bove function
def main():
	txt = "ABAAABCDABC"
	pat = "ABC"
	search(txt, pat)

if __name__ == '__main__':
	main()

# This code is contributed by Atul Kumar
# (www.facebook.com/atul.kr.007)
