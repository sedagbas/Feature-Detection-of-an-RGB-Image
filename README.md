The purpose of this project is to implement a class hierarchy to detect features (lines and corners) in an RGB image. In this project, the OpenCV library is used to perform manipulations on RGB images.

   1. The “CommonProcesses” class serves as the base class, encapsulating common functionalities for working with RGB images. It includes methods for reading and writing RGB data to/from files, image manipulation (e.g., grayscale conversion, noise filtering, and resizing), and visualization. The class also enforces validation checks during object initialization to ensure data integrity.

   2. The “Detection” class is derived from the “CommonProcessess” class which introduces features specific to feature detection. It includes attributes to manage the type of detection, file-saving directory, and methods for visualizing and writing features to files. Overloaded operators facilitate the printing of corner and line coordinates in a suitable format. The constructor initializes parameters such as scale factor, type of detection, and file-saving directory.

   3. The “LineDetection” class is derived from the “Detection” class which specializes in detecting lines within an image. It includes methods to perform Canny edge detection and Hough Line Transform, along with post-processing steps like noise filtering and image rescaling. The class provides functionality to draw and display detected lines, leveraging the capabilities of the underlying OpenCV library.

   4. The “CornerDetection” class is derived from the “Detection” class and focuses on corner detection. It includes methods for corner detection, normalization, drawing corners on images, and creating circles around detected corners.

OUTPUTS

LINES: (0, 60)(133, 9), (206, 56)(262, 51), (0, 96)(143, 58), (1, 81)(80, 71), (28, 158)(198, 155), (13, 118)(124, 100), (1, 130)(108, 123), (172, 170)(243, 170), (96, 170)(155, 171), (115, 72)(242, 59), (164, 58)(262, 49), (40, 37)(131, 2), (175, 100)(259, 97), (164, 57)(216, 44), (94, 116)(261, 108), (173, 82)(173, 27), (2, 70)(131, 28), (2, 147)(70, 146), (11, 171)(103, 79), (0, 99)(63, 82), (171, 82)(260, 76), (1, 131)(53, 130), (178, 131)(253, 135), (171, 81)(256, 70), (13, 177)(67, 123), (177, 143)(254, 143), (3, 70)(66, 56), (193, 58)(261, 25), (205, 31)(262, 19), (178, 123)(239, 118), (89, 131)(140, 127), (153, 104)(262, 98), (31, 33)(112, 0), (161, 34)(212, 21), (178, 126)(253, 126), (97, 53)(162, 38), (93, 114)(199, 109), (106, 153)(164, 154), (3, 154)(54, 152), (3, 75)(81, 68), (176, 39)(239, 14), (1, 135)(71, 138), (186, 80)(258, 73), (178, 127)(253, 130), (151, 7)(211, 0), (4, 107)(89, 92), (3, 144)(71, 144), (71, 48)(215, 23), (49, 96)(116, 87), (0, 84)(50, 77), (177, 140)(240, 136), (178, 130)(253, 133), (197, 142)(254, 139), (35, 123)(96, 121), (178, 125)(239, 122), (8, 150)(70, 147), (31, 100)(86, 78), (3, 141)(71, 142), (15, 100)(77, 83)

![Line_Detection](https://github.com/sedagbas/Feature-Detection-of-an-RGB-Image/assets/159046448/e370e9eb-c060-4160-ba24-b8bcea01c5b6)

CORNERS: (84, 19), (253, 24), (254, 24), (254, 25), (224, 29), (208, 30), (32, 33), (38, 37), (38, 38), (210, 41), (220, 45), (220, 46), (254, 50), (255, 50), (256, 50), (257, 50), (254, 51), (228, 53), (229, 53), (230, 53), (231, 53), (242, 53), (218, 54), (230, 54), (194, 56), (195, 56), (196, 56), (80, 74), (81, 74), (256, 75), (244, 76), (172, 81), (173, 81), (172, 82), (250, 115), (42, 149), (25, 150), (22, 152), (38, 152), (22, 153), (97, 170)

![Corner_Detection](https://github.com/sedagbas/Feature-Detection-of-an-RGB-Image/assets/159046448/16db85aa-1f7f-4ee3-9904-ddb948276735)
