"""
    static class method
    static class data member
"""

class C:
    static_data = 10    # static/class data member

    def __init__(self):
        self.m = 7      # instance 

    @staticmethod       # function decorator
    def foo():
        print "foo() is static method. Accessing static data member: " + str(C.static_data)     # need to specify C.static_data

C.foo()
