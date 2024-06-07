from django.shortcuts import render, redirect
from django.http import HttpResponse, Http404, HttpResponseRedirect
from restapp.models import Restaurant, Dish
from restapp.forms import EmployeeForm, NameForm, RestaurantForm, DishForm


# Create your views here.

def restaurants(request):
    restaurants = Restaurant.objects.all()

    return render(request, "restaurants.html", {"restaurants": restaurants, "new_var": 1})

def restaurant_detail(request, restaurant_id):
    restaurant = Restaurant.objects.get(id=restaurant_id)
    return render(request, 'restaurant_detail.html', {'restaurant': restaurant})
    # return HttpResponse(f"<p>Restaurant details for restaurant with id = {restaurant_id}.</p><p> Restaurant name: {restaurant.name}, capacity: {restaurant.capacity}</p>")

def dishes(request):
    dishes = Dish.objects.all()

    return render(request, "dishes.html", {"dishes": dishes, "count": len(dishes)})

def dish_detail(request, dish_id):
    try:
        dish = Dish.objects.get(id=dish_id)
    except Dish.DoesNotExist:
        raise Http404("Dish does not exist!")
    return HttpResponse(dish)

def index(request):
    if request.method == "POST":
        form = NameForm(request.POST)
        if form.is_valid():
            request.session['your_name'] = form.cleaned_data['your_name']
    else:
        form = NameForm()

    if 'your_name' not in request.session:
        your_name = "Anonymous"
    else:
        your_name = request.session['your_name']

    return render(request, "index.html", {"form": form, "your_name": your_name})

def add_restaurant(request):
    if request.method == "POST":
        restaurant = RestaurantForm(request.POST)
        if restaurant.is_valid():
            restaurant.save()
            return redirect("restaurants")
    else:
        restaurant = RestaurantForm()
    return render(request, "add_restaurant.html", {"form": restaurant})

def add_dish(request):
    if request.method == "POST":
        dish = DishForm(request.POST)
        if dish.is_valid():
            dish.save()
            return redirect("dishes")
    else:
        dish = DishForm()
    return render(request, "add_dish.html", {"form": dish})

def edit_restaurant(request, id):
    restaurant_instance = Restaurant.objects.filter(id=id).get()
    if request.method == "POST":
        restaurant = RestaurantForm(request.POST, instance=restaurant_instance)
        if restaurant.is_valid():
            restaurant.save()
        return redirect("restaurants")
    else:
        restaurant = RestaurantForm(instance=restaurant_instance)

    return render(request, "edit_restaurant.html", {"form": restaurant})

def delete_restaurant(request, id):
    restaurant_instance = Restaurant.objects.filter(id=id).get()
    if request.method == "POST":
        restaurant_instance.delete()
        return redirect("restaurants")

    return render(request, "delete_restaurant.html")
def add_employee(request, id):
    if request.method == "POST":
        employee = EmployeeForm(request.POST)
        if employee.is_valid():
            if not request.user.is_anonymous:
                employee.instance.user = request.user
                employee.save()
                employee = EmployeeForm()
            else:
                employee.add_error(None, "You must log in.")
        else:
            print(employee.errors)
    else:
        employee = EmployeeForm()
    return render(request, "add_employee.html", {"form": employee})