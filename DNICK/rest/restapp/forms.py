from django import forms

from restapp.models import Restaurant, Employee, Dish

class NameForm(forms.Form):
    your_name = forms.CharField(label="Your name is ", max_length=20)

class RestaurantForm(forms.ModelForm):
    def __init__(self, *args, **kwargs):
        super(RestaurantForm, self).__init__(*args, **kwargs)
        for field in self.visible_fields():
            field.field.widget.attrs["class"] = " form-control"
    class Meta:
            model = Restaurant
            fields = "__all__"

class DishForm(forms.ModelForm):
    def __init__(self, *args, **kwargs):
        super(DishForm, self).__init__(*args, **kwargs)
        for field in self.visible_fields():
            field.field.widget.attrs["class"] = " form-control"
    class Meta:
        model = Dish
        fields = "__all__"

class EmployeeForm(forms.ModelForm):
    class Meta:
        model = Employee
        fields = "__all__"
        exclude = ["user"]