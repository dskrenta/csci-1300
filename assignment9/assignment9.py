'''
Author: David Skrenta CS1300 Fall 2017
Recitation: 210 - Arcadia
Assignment 9
assignment9.py
'''

def compute_census(rates, population):
    '''
    Computes the current population after a year based on the rates provided
    params: rates, population
    returns: population
    '''

    seconds_per_year = 31536000

    population += seconds_per_year / rates[0]
    population -= seconds_per_year / rates[1]
    population += seconds_per_year / rates[2]

    return population

def convert_seconds():
    '''
    Converts seconds to days, hours, minutes, seconds format based on seconds from user input
    '''

    total_seconds = input("Enter the number of seconds you want to convert?")

    if total_seconds < 0:
        total_seconds = 0

    days = total_seconds / (24 * 60 * 60)
    total_seconds = total_seconds % (24 * 60 * 60)
    hours = total_seconds / (60 * 60)
    total_seconds = total_seconds % (60 * 60)
    minutes = total_seconds / 60
    seconds = total_seconds % 60

    print str(total_seconds) + " corresponds to: " + str(days) + " days, " + str(hours) + " hours, " + str(minutes) + " minutes, " + str(seconds) + " seconds."

def generate_story(params):
    '''
    Generates a story based on a list of prompts and strings
    params: params
    returns: story
    '''

    story = ""

    for i in xrange(1, len(params), 2):
        params[i] = raw_input(params[i])

    for i in xrange(1, len(params), 2):
        story += params[i - 1] + " " + params[i] + " "

    return story + params[len(params) - 1]

def similatiry_score(seq1, seq2):
    '''
    Computes the similatiry score of two strings based on their edit distance from eachother
    params: seq1, seq2
    returns: score
    '''

    length1 = len(seq1)
    length2 = len(seq2)

    if length1 != length2:
        return 0

    mismatches = 0

    for i in range(0, length1):
        if seq1[i] != seq2[i]:
            mismatches += 1

    return (float(length1) - float(mismatches)) / float(length2);

def best_match(genome, seq):
    '''
    Computes the best match for a string and a substring using similarity_score
    params: genome, seq
    returns: best match
    '''

    best_match = 0

    for i in range(0, len(genome)):
        score = similatiry_score(genome[i:len(seq) + 1], seq)
        if score > best_match:
            best_match = i

    return best_match

def calc_stats(list):
    '''
    Calculates the average and the median for a list
    params: list
    returns: average and median in list format
    '''

    median = 0
    sum = 0
    list.sort()
    size = len(list)

    if size % 2:
        median = list[size / 2]
    else:
        median = (list[size / 2] + list[(size / 2) - 1]) / 2

    for value in list:
        sum += value

    return [(sum / size), median]

def parse_ratings(filename):
    '''
    Reads a ratings file and populates a list with the values
    params: filename
    returns: ratings
    '''

    final_ratings = []
    file = open(filename, "r")

    for line in file:
        name_ratings = line.split(',')
        ratings = name_ratings[1].rstrip().split(' ')[1:]

        for i in range(0, len(ratings)):
            ratings[i] = int(ratings[i])

        final_ratings.append([name_ratings[0], ratings])

    return final_ratings

def main():
    rates = [8, 12, 33]
    population = 1000000
    print compute_census(rates, population)

    convert_seconds()

    params = ["I went skiing at", "Enter a location:", "it was really crowded and I stayed in line for", "Enter number of hours:", "hours"]
    print generate_story(params)

    print similatiry_score("ABCEABA", "ABCDABC")

    print best_match("ABCABCGHC", "GHC")

    print calc_stats([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

    print parse_ratings("ratings.txt")

if __name__ == "__main__":
    main()
