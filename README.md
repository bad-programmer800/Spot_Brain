# Spot_Brain
Science project 

The foundation of this project is Hazel Engine. The Cherno is amazing. As soon as I have glfw, Imgui, and Opengl I will branch into my own thing, but I really have no idea what I am doing!!!!!

At Commit #20, I made my very first non-Cherno element (I am currently up to Game Engine Ep. 40). It was just an empty ImGui window, but I'm very excited to figure out how to start passing different things into different windows and start gaining some extra functionality. Planning to play around with OpenCV in the near future.

12/12/2022. Commit added Frame Buffers and OpenCV. However, OpenCV was added to VS2022 by hand. I need to figure out how to update the premake file to add it upon project build. I have also gotten more comfortable with my understanding of ImGui windows. I am starting to create a potential UI setup for Spot_Brain project number 1. Use the Hazel framework to set up image processing as done in "wholebrain".

Future Project #1
Create a viewport that takes in an image. A zoom checkbox turns on a square zoom window of a ROI (region of interest). Thresholding operations are done on the pixels to highlight certain features. The data from the highlighted features is then segmented into data objects.
