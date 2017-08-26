#coding=utf-8
from __future__ import division
import matplotlib.pyplot as plt
import matplotlib.image as img 
import numpy as np

img = img.imread("test.jpg")
print img.shape
#plt.imshow(img)
#plt.axis('off')
#plt.show()

#img = img[:,550:960,::]
print img.shape

plt.axis('off')
plt.imshow(img)
#plt.figure(figsize=(img.shape[0],img.shape[1]))
plt.savefig("cut.jpg", bbox_inches='tight', dpi=1)
#plt.show()

gray=np.dot(img[...,:3], [0.33, 0.33, 0.34])
print gray.shape

plt.imshow(gray, cmap=plt.cm.gray)
plt.axis('off')
plt.savefig("gray.jpg", bbox_inches='tight')
#plt.savefig("")

mean = np.mean(gray)
pic = np.sign(mean - gray) 
colored_pic = np.zeros(img.shape, dtype=np.int32)

alpha = 0.7
beta = 0.3
max_color1 = np.dot(np.array([alpha, beta]), gray.shape)
max_color2 = np.dot(np.array([beta, alpha]), gray.shape)

for i in range(gray.shape[0]):
    for j in range(gray.shape[1]):

        c_step = (alpha * i + beta * j) / max_color1;
        g = c_step * 255
        r = (gray.shape[0] - i) / gray.shape[0] * 255
        b = j / gray.shape[1] * 255


        if pic[i][j] > 0 and i < 739:
            colored_pic[i][j][0]= r
            colored_pic[i][j][1]= g
            colored_pic[i][j][2]= b #int(b * l)
        else:
            colored_pic[i][j][0] =  255 - r 
            colored_pic[i][j][1] =  255 - g
            colored_pic[i][j][1] =  255 - b


#plt.imshow(pic)
#plt.axis('off')
#plt.show()

print colored_pic.shape

plt.imshow(colored_pic)
plt.axis('off')
plt.savefig(".jpg")
plt.savefig("colorful.jpg", bbox_inches='tight')
#plt.show()

