'''
Author: David Skrenta CS1300 Fall 2017
Recitation: 210 - Arcadia
Assignment 10
assignment10.py
'''

class Recommender:
    def __init__(self, books_filename, ratings_filename):
        self.read_books(books_filename)
        self.read_users(ratings_filename)
        
    def read_books(self, file_name):
        self.books = []
        file = open(file_name, 'r')
        
        for line in file:
            values = line.rstrip().split(',')
            self.books.append([values[1], values[0]])
        
    def read_users(self, user_file):
        self.users = {}
        file = open(user_file, 'r')
        
        for line in file:
            values = line.rstrip().split(' ')
            self.users[values[0]] = values[1:]
        
def main():
    recommender = Recommender('book.txt', 'ratings.txt')
    
    print recommender.books
    print recommender.users 

if __name__ == '__main__':
    main()