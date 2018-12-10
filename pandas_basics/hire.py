import numpy as np 			
import pandas as pd 		#for cleaning data

#reading data from csv to a variable
data = pd.read_csv("PastHires.csv")

# how many rows and colums in data
print(data.shape)

#how many rows
print(len(data))

# columns in a list
print(data.columns)

#extracting a single column
print(data['Hired'])

#extracting a range of rows from a column
print(data['Hired'] [:5])

#extracting a single value 
print(data['Hired'][5])

#exteacting multypul columns

print(data[['Years Experience','Hired']])

#sort according to the value of the given colum 
print(data.sort_values(['Years Experience']))

#value count - very useful to find outliers 
degree_count = data['Level of Education'].value_counts()
print(degree_count)


