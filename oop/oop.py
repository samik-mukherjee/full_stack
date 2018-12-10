# Object oriented programming in pyhton 

class Employee(object):

	# class variable
	emlpoyee_count = 0
	raise_amount = 1.4

	#defines what should go inside eash instance
	def __init__(self, first, last, pay):

	# instance variables
		self.first = first
		self.last = last
		self.email = first  + '.' + last + '@company.com'
		self.pay = pay

	# for each instance employee_count will go up by 1
		Employee.emlpoyee_count += 1

	def fullname(self):
		return '{} {}'.format(self.first,self.last)

	def apply_raise(self):
		self.pay = int(self.pay * self.raise_amount)


#creats a instance of Employee class and raise pay
emp_1 = Employee('Samik','Mukherjee',1000000000)
emp_1.apply_raise()


print('{} makes ${} a year ! that is crazy!\twow!' 
	.format(Employee.fullname(emp_1),emp_1.pay))

# prints all the attributes of emp_1
print("All the attributes of Employee class are :\n {}"
	.format(Employee.__dict__))
print('total employee number is: {}'
	.format(Employee.emlpoyee_count))


