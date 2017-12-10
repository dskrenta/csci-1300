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

def calculate_average_rating(ratings_dict):
    avg_ratings = []

    for value in ratings_dict.iteritems():
        sum = 0.0
        count = 0

        for rating in value[1]:
            if rating != 0:
                sum += rating
                count += 1

        avg_ratings.append(sum / count)
        # avg_ratings.insert(value[1], sum / count)

    return avg_ratings

def lookup_average_rating(index, book_dict, avg_ratings_dict):
    return '(' + '{0:.2f}'.format(avg_ratings_dict[index]) + ')' + ' ' + book_dict[index][0] + ' by ' + book_dict[index][1]

class Recommender:
    def __init__(self, books_filename, ratings_filename):
        self.book_list = []
        self.user_dictionary = {}
        self.average_rating_list = []
        # [name1, name2, name3]

        self.read_books(books_filename)
        self.read_users(ratings_filename)
        self.calculate_average_rating()

    def read_books(self, file_name):
        try:
            file = open(file_name, 'r')

            for line in file:
                values = line.rstrip().split(',')
                self.book_list.append([values[1], values[0]])
        except:
            return None

    def read_users(self, user_file):
        users = {}

        try:
            file = open(user_file, 'r')

            for line in file:
                values = line.rstrip().split(' ')
                self.user_dictionary[values[0]] = map(lambda rating: int(rating), values[1:])
                # self.average_rating_list.append(0)
        except:
            return None

    '''
    def calculate_average_rating(self):
        for i in range(0, len(self.average_rating_list)):
            ratings = self.user_dictionary[self.average_rating_list[i]]
            sum = 0.0
            count = 0

            for rating in ratings:
                if rating != 0:
                    sum += rating
                    count += 1

            self.average_rating_list[i] = sum / count
    '''

    '''
    def calculate_average_rating(self):
        for i in range(0, len(self.average_rating_list)):
            ratings = self.user_dictionary[self.average_rating_list[i]]
            sum = 0.0
            count = 0

            for rating in ratings:
                if rating != 0:
                    sum += rating
                    count += 1

            # self.average_rating_list[i] = sum / count
            # print i, sum / count
            self.average_rating_list.insert(i, sum / count)
    '''

    def lookup_average_rating(self, index):
        return '(' + '{0:.2f}'.format(self.average_rating_list[index]) + ')' + ' ' + self.book_list[index][0] + ' by ' + self.book_list[index][1]

    def calc_similarity(self, user1, user2):
        sum = 0.0

        for i in range(0, len(self.user_dictionary[user1])):
            sum += self.user_dictionary[user1][i] * self.user_dictionary[user2][i]

        return int(sum)

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
                recommend_list.append(self.lookup_average_rating(i))

        return recommend_list

def main():
    book_list = read_books("../book.txt")
    user_dict = read_users("../ratings.txt")

    ### Test case for the part 1
    ave_rating_list = calculate_average_rating(user_dict)
    print round(ave_rating_list[0], 3) 	# 3.833
    print ave_rating_list[20]  		# 0.5
    print lookup_average_rating(0, book_list, ave_rating_list)
    # (3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams


    ### Test case for part 2
    r = Recommender("../book.txt", "../ratings.txt")

    #### calc_similarity function:
    print r.calc_similarity('Cust8', 'Shannon')      # 369
    print r.calc_similarity('Megan', 'Strongbad')    # 95
    print r.calc_similarity('Leah', 'clipper')       # 0
    print r.calc_similarity('Apollo', 'James')       # -65

    #### lookup_average_rating function
    print r.lookup_average_rating(0)            # (3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams
    print r.lookup_average_rating(7)            # (0.43) The Sisterhood of the Travelling Pants by Ann Brashares
    print r.lookup_average_rating(17)           # (2.38) Neuromancer by William Gibson
    print r.lookup_average_rating(30)           # (1.77) To Kill a Mockingbird by Harper Lee
    print r.lookup_average_rating(54)  	    # (1.56) The Chrysalids by John Wyndham
    print r.lookup_average_rating(10)  	    #(0.90) The Princess Diaries by Meg Cabot
    # -> it should be (0.90), NOT (0.9)

    #### get_most_similar_user
    print r.get_most_similar_user("Leah")       # hidan
    print r.get_most_similar_user("Rudy_Ann")   # ROFLOL
    print r.get_most_similar_user("Martin")     # clipper
    print r.get_most_similar_user("KeeLed")     # Cust8
    print r.get_most_similar_user("Rudy.A")     # Cust8


    #### recommend_books
    print r.recommend_books("Brian")
    # []
    print r.recommend_books("Megan")
    # ['(0.90) The Princess Diaries by Meg Cabot',
    #  "(3.80) My Sister's Keeper by Jodi Picoult",
    #  '(2.06) Bone Series by Jeff Smith']
    print r.recommend_books("Tiffany")
    # ['(3.86) The Bourne Series by Robert Ludlum']
    print r.recommend_books("Moose")
    # ['(3.50) The Princess Bride by William Goldman',
    #  '(3.86) The Bourne Series by Robert Ludlum',
    #  '(0.47) Twilight Series by Stephenie Meyer',
    #  '(2.76) The Golden Compass by Philip Pullman',
    #  '(3.57) Holes by Louis Sachar']
    print r.recommend_books("Ella")
    # ["(3.83) The Hitchhiker's Guide To The Galaxy by Douglas Adams",
    #  '(2.25) The Da Vinci Code by Dan Brown',
    #  '(1.62) Naruto by Masashi Kishimoto',
    #  '(3.86) The Bourne Series by Robert Ludlum',
    #  "(3.80) My Sister's Keeper by Jodi Picoult",
    #  '(3.61) Harry Potter Series by J.K. Rowling',
    #  '(2.06) Bone Series by Jeff Smith',
    #  '(3.04) The Lord of the Rings by J R R Tolkien',
    #  '(2.85) The Hobbit by J R R Tolkien',
    #  '(2.83) The War Of The Worlds by H G Wells']

if __name__ == '__main__':
    main()
