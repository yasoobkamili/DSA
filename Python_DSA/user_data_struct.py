class User:
    def __init__(self,username,name,email):
        self.username = username
        self.name = name
        self.email = email
        print('User Created!')
    def introduce_yourself(self,guest_name):
        print('Hi {}!. I\'m {}. Reach to me at {}'.format(guest_name,self.name,self.email))   
    def __repr__(self):
        return "User(username = {}, name = {}, email = {})".format(self.username, self.name,self.email)
    def __str__(self):
        return self.__repr__()
user1 = User('yasoob','Yasoob Kamili','kamiliyasoob@gmail.com')
print('user1:',user1.name)
print(user1)
user1.introduce_yourself('John Doe')        