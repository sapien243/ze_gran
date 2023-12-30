import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    persondb = []
    with open(sys.argv[1], 'r') as dnaData:
        reader = csv.reader(dnaData)
        strs = next(reader)
        for row in reader:
            persondb.append(row)

    strs.pop(0)
    numPep = len(persondb)
    numStr = len(strs)

    # TODO: Read DNA sequence file into a variable
    dnaString = open(sys.argv[2])
    sequence = dnaString.read()
    dnaString.close()

    # TODO: Find longest match of each STR in DNA sequence
    maxStr = [0] * numStr
    for x in range(numStr):
        maxStr[x] = longest_match(sequence, strs[x])

    # TODO: Check database for matching profiles
    statement = "No match"
    for y in range(numPep):
        for z in range(numStr):
            if int(persondb[y][z + 1]) != maxStr[z]:
                full = False
                break
            full = True
        if full:
            statement = persondb[y][0]
            break

    print(statement)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
