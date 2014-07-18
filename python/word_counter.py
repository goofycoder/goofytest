from collections import Counter

words = [
   'look', 'into', 'my', 'eyes', 'look', 'into', 'my', 'eyes',
   'the', 'eyes', 'the', 'eyes', 'the', 'eyes', 'not', 'around', 'the',
   'eyes', "don't", 'look', 'around', 'the', 'eyes', 'look', 'into',
   'my', 'eyes', "you're", 'under'
]

word_counts = Counter(words)

top_three = word_counts.most_common(3)

print(top_three)
# Output: [('eyes', 8), ('the', 5), ('look', 4)]

print word_counts["you're"]
# output: 1
