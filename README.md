# Interactive Numerical Inquiry
## The goals for this project
- Implement facade classes which use concrete math libraries.


## Specs
This project makes use of Qwt 6.1.3 as of 9/8/16.
My configuration: Windows 10
    Qt Creator 4.1.0, Based on Qt 5.7.0(MSVC 2013, 32 bit). This is a
    requirement to use Qwt widgets.
Because my Qt is based on MSVC 2013, 32 bit, I have to build Qwt using the
same compiler in order for it to be compatible with Qt Creator (and Designer
within Qt Creator).
Installed as follows:

1. extract qwt-6.1.3 into C:\Qwt-6.1.3. In that same folder, paste the file
qwt-6.1.3.qhc which is on the sourceforge download page for Qwt.
2. Click on qwt.pro to open it on Qt Creator(assuming it's installed).
3. On Qt Creator, click on the big button called "Projects" on the left side
    panel.
... To be continued (Qwt is not yet necessary).

- LAPACK built using CMAKE 3.5.2 (Generator: 'MinGW Makefiles')


## References/ Notes / Resources
Info on facade design pattern:
    https://en.wikipedia.org/wiki/Facade_pattern
- "Delegates" control the rendering and editing of individual items in views.
- http://stackoverflow.com/questions/4553304/understanding-form-layout-mechanisms-in-qt

To build lapack. I followed the instructions below "Build Instructions to
create LAPACK and LAPACKE 3.5.0 dlls for Windows with MinGW"
- http://icl.cs.utk.edu/lapack-for-windows/lapack/#libraries_intel


/*
 *   MEMORYSTATUSEX statex;
  statex.dwLength = sizeof(statex);
  GlobalMemoryStatusEx(&statex);
  qDebug("There is  %*ld percent of memory in use.\n",
            WIDTH, statex.dwMemoryLoad);
  qDebug("There are %*I64d total KB of physical memory.\n",
            WIDTH, statex.ullTotalPhys/DIV);
  qDebug("There are %*I64d free  KB of physical memory.\n",
            WIDTH, statex.ullAvailPhys/DIV);
  qDebug("There are %*I64d total KB of paging file.\n",
            WIDTH, statex.ullTotalPageFile/DIV);
  qDebug("There are %*I64d free  KB of paging file.\n",
            WIDTH, statex.ullAvailPageFile/DIV);
  qDebug("There are %*I64d total KB of virtual memory.\n",
            WIDTH, statex.ullTotalVirtual/DIV);
  qDebug("There are %*I64d free  KB of virtual memory.\n",
            WIDTH, statex.ullAvailVirtual/DIV);
  // Show the amount of extended memory available.
  qDebug("There are %*I64d free  KB of extended memory.\n",
            WIDTH, statex.ullAvailExtendedVirtual/DIV);

*/

/*

  _SYSTEM_INFO sysinfo;
  GetNativeSystemInfo(&sysinfo);
  ui->stackedWidget->setCurrentIndex(0);
  qDebug() << _MSC_VER << "->" << _MSC_BUILD << "->" << _MSC_FULL_VER << "->"
            << _MSC_VER << "->" << sysinfo. << '\n';

  GetSystemInfo(&sysinfo);
  printf("OEM ID: %u\n", sysinfo.dwOemId);
  printf("Number of processors: %u\n", sysinfo.dwNumberOfProcessors);
  printf("  Minimum application address: %lx\n",
      sysinfo.lpMinimumApplicationAddress);
  printf("  Maximum application address: %lx\n",
      sysinfo.lpMaximumApplicationAddress);
  printf("  Active processor mask: %u\n",
      sysinfo.dwActiveProcessorMask);

*/

* To simplify the creation of markdown files:
    http://daringfireball.net/projects/markdown/dingus
