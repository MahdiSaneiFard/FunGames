# استفاده از یک ایمیج پایه که Qt را دارد
FROM ubuntu:22.04

# جلوگیری از توقف برای تنظیمات منطقه زمانی
ENV DEBIAN_FRONTEND=noninteractive

# نصب کتابخانه‌های مورد نیاز Qt و کامپایلر
RUN apt-get update && apt-get install -y \
    build-essential \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libqt5sql5-sqlite \
    && rm -rf /var/lib/apt/lists/*

# تعیین پوشه کاری داخل کانتینر
WORKDIR /app

# کپی کردن تمام فایل‌های پروژه به داخل کانتینر
COPY . .

# اجرای qmake و سپس make برای بیلد کردن پروژه
RUN qmake FunServer.pro && make

# باز کردن پورت سرور (پورتی که در کد سرور تنظیم کردی، مثلاً 1234)
EXPOSE 12345

# دستور اجرای برنامه (نام فایل خروجی را جایگزین ServerExeName کن)
CMD ["./FunServer"]
