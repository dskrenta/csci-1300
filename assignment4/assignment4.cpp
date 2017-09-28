// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 4
// assignment4.cpp

#include <iostream>
#include <string>

using namespace std;

/*
  Compares two strings together and calculates their similarity
  Parameters: first sequence, second sequence
  Returns: similarity score for the two sequences
*/

float similarityScore(string sequence1, string sequence2) {
  float sequence1Length = sequence1.length();
  float sequence2Length = sequence2.length();

  if (sequence1Length != sequence2Length) {
    return 0;
  }

  float mismatches = 0.0;

  for (int i = 0; i < sequence1Length; i++) {
    if (!(sequence1[i] == sequence2[i])) {
      mismatches++;
    }
  }

  return (sequence1Length - mismatches) / sequence1Length;
}

/*
  Counts all matches of a sequence in a genome with a minimun score consideration
  Parameters: genome, sequence, minScore
  Returns: all matches within the min score boundary
*/

int countMatches(string genome, string sequence, float minScore) {
  int matches = 0;
  int sequenceLength = sequence.length();

  for (int pos = 0; pos < genome.length() - sequenceLength + 1; pos++) {
    float score = similarityScore(genome.substr(pos, sequenceLength), sequence);
    if (score >= minScore) {
      matches++;
    }
  }

  return matches;
}

/*
  Finds the best match in terms of similarity for a genome and a sequence
  Parameters: genome, sequence
  Returns: best match
*/

float findBestMatch(string genome, string seq) {
  float bestMatch = 0.0;

  for (int pos = 0; pos < genome.length(); pos++) {
    float score = similarityScore(genome.substr(pos, seq.length()), seq);
    if (score > bestMatch) {
      bestMatch = score;
    }
  }

  return bestMatch;
}

/*
  Compares three genomes and returns the index number of the one with the best match for a sequence
  Parameters: first genome, second genome, third genome, sequence
  Returns: best matching genome for given sequence
*/

int findBestGenome(string genome1, string genome2, string genome3, string seq) {
  float genome1Score = findBestMatch(genome1, seq);
  float genome2Score = findBestMatch(genome2, seq);
  float genome3Score = findBestMatch(genome3, seq);

  if (genome1Score > genome2Score && genome1Score > genome3Score) {
    return 1;
  }
  else if (genome2Score > genome1Score && genome2Score > genome3Score) {
    return 2;
  }
  else if (genome3Score > genome1Score && genome3Score > genome2Score) {
    return 3;
  }
  else {
    return 0;
  }
}

/*
  Calculates the complement sequence given a sequence of DNA
  Parameters: sequence
  Returns: complement sequence
*/

string complementSequence(string seq) {
  string complementSeq = "";

  for (int i = 0; i < seq.length(); i++) {
    if (seq[i] == 65) {
      complementSeq += "T";
    }
    else if (seq[i] == 67) {
      complementSeq += "G";
    }
  }

  return complementSeq;
}

/*
  Calculates the reverse complement sequence given a sequence of DNA
  Parameters: sequence
  Returns: reverse complement sequence
*/

string reverseComplementSequence(string seq) {
  string complementSeq = complementSequence(seq);
  string reverseComponentSeq = "";

  for (int i = complementSeq.length(); i > 0; i--) {
    reverseComponentSeq += complementSeq[i];
  }

  return reverseComponentSeq;
}
