class Average:
    def __init__(self):
        self.dict_of_average = {}

    def load_dictionary(self, filename):
        try:
            file = open(filename, 'r')
            for line in file:
                values = line.rstrip().split(' ')
                sum = 0.0
                for i in range(1, len(values)):
                    print values[i], i, len(values)
                    sum += int(values[i])
                print sum
                self.dict_of_average[values[0]] = sum / (len(values) - 1)
        except:
            return None

    '''
    def load_dictionary(self, filename):
        try:
            file = open(filename, 'r')
            for line in file:
                values = line.strip().split(' ')
                sum = 0
                for i in range(1, len(values)):
                    sum += values[i]
                self.dict_of_average[values[0]] = sum / len(values) - 1
            file.close()
            return self.dict_of_average
        except:
            return None
    '''

    def highestAverage(self):
        max = 0.0
        max_key = ''
        for key in self.dict_of_average:
            if self.dict_of_average[key] > max:
                max_key = key
                max = self.dict_of_average[key]
        print max_key + ', Average: ' + str(max)

def main():
    a1 = Average();
    a1.load_dictionary("test_file.txt")
    print(a1.dict_of_average)
    a1.highestAverage()

main()
