#!/usr/bin/perl -w

use strict;

open INF, "find .. -name triangle.cpp |" or die;
while (my $line = <INF>) {
    chomp $line;
    die unless ($line =~ /\.\.\/([a-zA-Z0-9]+)\//);
    my $who = $1;
    print "<$line> $who\n";
    system "clang++ -std=c++11 -Wall -Werror -fsanitize=undefined,address $line";
    system "./a.out < tests.txt > output-${who}.txt";
}
