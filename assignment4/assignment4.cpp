#include <iostream>
#include <string>

using namespace std;

float similarityScore(string sequence1, string sequence2) {
  float sequence1Length = sequence1.length();
  float sequence2Length = sequence2.length();

  if (sequence1Length != sequence2Length) {
    return 0;
  }

  float matches = 0.0;
  float mismatches = 0.0;

  for (int i = 0; i < sequence1Length; i++) {
    if (sequence1[i] == sequence2[i]) {
      matches++;
    }
    else {
      mismatches++;
    }
  }

  return (matches - mismatches) / sequence1Length;
}

int countMatches(string genome, string sequence1, float minScore) {
  int matches = 0;
  int genomeLength = genome.length();
  int sequence1Length = sequence1.length();
  int pos = 0;

  for (int pos = 0; pos < genome.length(); pos += sequence1Length) {
    float score = similarityScore(genome.substr(pos, sequence1Length), sequence1);
    if (score >= minScore) {
      matches++;
    }
  }

  return matches;
}

float findBestMatch(string genome, string seq) {
  float bestMatch = 0.0;
  int genomeLength = genome.length();
  int seqLength = seq.length();
  int pos = 0;

  for (int pos = 0; pos < genome.length(); pos += seqLength) {
    float score = similarityScore(genome.substr(pos, seqLength), seq);
    if (score > bestMatch) {
      bestMatch = score;
    }
  }

  return bestMatch;
}

int findBestGenome(string genome1, string genome2, string genome3, string seq) {
  float genome1Score = similarityScore(genome1, seq);
  float genome2Score = similarityScore(genome2, seq);
  float genome3Score = similarityScore(genome3, seq);

  if (genome1Score > genome2Score && genome1Score > genome3Score) return 1;
  else if (genome2Score > genome1Score && genome2Score > genome3Score) return 2;
  else if (genome3Score > genome1Score && genome3Score > genome2Score) return 3;
  else return 0;
}
