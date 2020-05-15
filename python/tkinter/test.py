try:
    import tkinter # This is used in python 3
except ImportError:
    import Tkinter as tkinter # This is used in python 2

import random
    

def insult(): # A function that randomly insults you

    insults = ["Human!", "Person!", "Vegetable!", "Animal!", "Planet!", "Star!",
                                                                     "Galaxy!"]
    choice = random.choice(insults)
    global last_choice
    while (choice == last_choice): # Do not choose the same insult twice in a row
        choice = random.choice(insults)
    last_choice = choice
    print(choice) # Print choice to the standard output device 
    label.config(text = choice) # Write choice into label, the widget defined below

# The program starts here
    
tk = tkinter.Tk() # Create the main window
# (also known as the root tkinter widget)

canvas = tkinter.Canvas(tk, width = 640, height = 480)
canvas.pack() # Add canvas to the window

canvas.create_line(0, 0, 640, 100, fill = "red")
canvas.create_text(100, 50, fill = "magenta", text = "This is a text.")
canvas.create_oval(50, 100, 100, 150, fill = "orange", outline = "blue")

button = tkinter.Button(tk, text = "Insult", command = insult); # insult is the function defined above
canvas.create_window(200, 200, window = button); # Add button to the canvas

last_choice = ""
label = tkinter.Label(tk, text = last_choice);
canvas.create_window(400, 200, window = label); # Add text label to the canvas

tk.mainloop()
