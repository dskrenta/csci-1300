'''
Author: David Skrenta CS1300 Fall 2017
Recitation: 210 - Arcadia
Assignment 10
assignment10.py
'''

def read_books(file_name):
    books = []

    try:
        file = open(file_name, 'r')

        for line in file:
            values = line.rstrip().split(',')
            books.append([values[1], values[0]])

        return books
    except:
        return None

def read_users(user_file):
    users = {}

    try:
        file = open(user_file, 'r')

        for line in file:
            values = line.rstrip().split(' ')
            users[values[0]] = map(lambda rating: int(rating), values[1:])

        return users
    except:
        return None

def calc_avg_rating(ratings_dict):
    avg_ratings = []

    for value in ratings_dict.iteritems():
        sum = 0.0
        count = 0

        for rating in value[1]:
            if rating > 0:
                sum += rating
                count += 1

        avg_ratings.append(sum / count)

    return avg_ratings

def lookup_avg_rating(index, book_dict, avg_ratings_dict):
    return '(' + str(avg_ratings_dict[index]) + ')' + ' ' + books_dict[index][0] + ' by ' + books_dict[index][1]

class Recommender:
    def __init__(self, books_filename, ratings_filename):
        self.book_list = self.read_books(books_filename)
        self.user_dictionary = self.read_users(ratings_filename)
        self.average_rating_list = []

    def read_books(self, file_name):
        books = []

        try:
            file = open(file_name, 'r')

            for line in file:
                values = line.rstrip().split(',')
                books.append([values[1], values[0]])

            return books
        except:
            return None

    def read_users(self, user_file):
        users = {}

        try:
            file = open(user_file, 'r')

            for line in file:
                values = line.rstrip().split(' ')
                users[values[0]] = map(lambda rating: int(rating), values[1:])

            return users
        except:
            return None

    def calc_avg_rating(self):
        for value in self.user_dictionary.iteritems():
            sum = 0.0
            count = 0

            for rating in value[1]:
                if rating > 0:
                    sum += rating
                    count += 1

            self.average_rating_list.append(sum / count)

    def lookup_avg_rating(self, index):
        return '(' + str(self.average_rating_list[index]) + ')' + ' ' + self.book_list[index][0] + ' by ' + self.book_list[index][1]

    def calc_similarity(self, user1, user2):
        sum = 0.0

        for i in range(0, len(self.user_dictionary[user1])):
            sum += self.user_dictionary[user1][i] * self.user_dictionary[user2][i]

        return sum

    def get_most_similar_user(self, current_user_id):
        max_similarity = 0.0
        max_user_id = ''

        for user in self.user_dictionary:
            if user != current_user_id:
                similarity = self.calc_similarity(current_user_id, user)
                if similarity > max_similarity:
                    max_similarity = similarity
                    max_user_id = user

        return max_user_id

    def recommend_books(self, current_user_id):
        similar_user_id = self.get_most_similar_user(current_user_id)
        recommend_list = []

        for i in range(0, len(self.user_dictionary[similar_user_id])):
            rating = self.user_dictionary[similar_user_id][i]
            if rating >= 3 and self.user_dictionary[current_user_id][i] == 0:
                recommend_list.append(self.lookup_avg_rating(i))

        return recommend_list

def main():
    recommender = Recommender('book.txt', 'ratings.txt')

    recommender.calc_avg_rating()

    # print recommender.lookup_avg_rating(5)

    # print recommender.calc_similarity('Ben', 'Moose')

    # print recommender.get_most_similar_user('Ben')

    print recommender.recommend_books('clipper')

if __name__ == '__main__':
    main()
