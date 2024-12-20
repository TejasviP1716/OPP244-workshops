/***************************************
Name - Tejasvi Parmar
student id - 151236239
email - tnparmar2@myseneca.ca
section - ZAA

******************************************/



#ifndef NAMESPACE_FILE_H // replace with relevant names
#define NAMESPACE_FILE_H
#pragma once
#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_

namespace seneca {

	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}

#endif
#endif