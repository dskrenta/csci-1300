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
            self.users[values[0]] = map(lambda rating: int(rating), values[1:])
            
    def calc_avg_rating(self):
        self.avg_ratings = []
        for value in self.users.iteritems():
            sum = 0.0
            count = 0
            for rating in value[1]:
                if rating > 0:
                    sum += rating
                    count += 1
            self.avg_ratings.append(sum / count)    
    
    def lookup_avg_rating(self, index):
        return '(' + str(self.avg_ratings[index]) + ')' + ' ' + self.books[index][0] + ' by ' + self.books[index][1]
        
def main():
    recommender = Recommender('book.txt', 'ratings.txt')
    
    # print recommender.books
    # print recommender.users
    
    recommender.calc_avg_rating() 
    
    # print recommender.avg_ratings
    print recommender.lookup_avg_rating(5)

if __name__ == '__main__':
    main()