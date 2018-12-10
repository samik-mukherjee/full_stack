from flask import Flask, render_template, url_for, flash, redirect
from forms import RegistrationForm,LoginForm
app = Flask(__name__)

app.config['SECRET_KEY'] = 'f83e7b3f05c0a6974185ccee4ad7c9b2'

posts = [
	{
		'writer': 'Samik Mukherjee',
		'title':'Blog post 1',
		'content': 'First blog post',
		'date_posted':'Dec 8th, 2018'
	},
	{
		'writer': 'Swarup Sarkar',
		'title':'Blog post 2',
		'content': 'Second blog post',
		'date_posted':'Dec 9th, 2018'
	}
]

#handling multipule routes with same function
@app.route('/')
@app.route('/home')
def home():
	return render_template('index.html', 
		posts=posts)

@app.route('/about')
def about():
	return render_template('about.html', 
		title='about')

# route to register page
@app.route('/register', methods =['GET','POST'])
def register():
	form = RegistrationForm()
	if form.validate_on_submit(): # account confirm message
		flash('Account created for {form.username.data}!',
			'success')
		return redirect(url_for('home'))
	return render_template('Register.html',
		title = 'register', form=form)

# route to login page
@app.route('/login')
def login():
	form = LoginForm()
	return render_template('Login.html',
		title = 'Login', form=form)


if __name__ == '__main__':
	app.run(debug=True)
