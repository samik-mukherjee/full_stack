class Dog(object):

	#class variable
	kind = "poodle"
	"""docstring for ClassName"""
	def __init__(self, name, age):
		self.name = name
		self.age = age

dog_1 = Dog('pinky', 5)
dog_1.kind = 'cat'
dog_1.kind = Dog.kind

print(dog_1.__dict__)
# print(Dog.__dict__)