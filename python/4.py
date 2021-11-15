[n , m] = list(map(int , input().split(" ")))

class Course:
    def __init__(self , num , score):
        self.num = num
        self.score = score

class Teacher:
    def __init__(self , name , cources):
        self.name = name
        self.cources = cources

courses = []

for i in range(n):
    [a , b , c ] = input().split(" ")
    course = Course( a , c )
    courses.append(course)

teachers = []

for i in range(m):
    teacherInfo = input().split(" ")
    teacher = Teacher( teacherInfo[1] , teacherInfo[2:] )
    teachers.append(teacher)

teacherWanted = input()

found = False

for teacher in teachers:
    if (teacher.name == teacherWanted):
        found = True
        count = 0
        total = 0
        for course in teacher.cources:
            count +=1
            for courseData in courses:
                if (course == courseData.num):
                    total += int( courseData.score)
                    break
        print(total / count)


if found == False:
    print("No this teacher")