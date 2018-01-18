#!/usr/bin/perl -w

use strict;

my @whos;

open INF, "find .. -name triangle.cpp |" or die;
while (my $line = <INF>) {
    chomp $line;
    die unless ($line =~ /\.\.\/([a-zA-Z0-9]+)\//);
    my $who = $1;
    print "============================================================================\n";
    print "compiling $line to $who\n";
    my $exe = "triangle-${who}";
    system "clang++ -std=c++11 -Wall -Werror -O $line -o triangle-$who";
    push @whos, $who;
    print "\n";
}
close INF;

my %map;
sub bypop {
    my $al = scalar(@{$map{$a}});
    my $bl = scalar(@{$map{$b}});
    return $bl <=> $al;
}

my $bad = 0;

open INF, "<tests.txt" or die;
while (my $line = <INF>) {
    open OUTF, ">one.txt" or die;
    print OUTF $line;
    close OUTF;
    %map = ();
    foreach my $who (@whos) {
        my $exe = "triangle-$who";
        if (!(-x $exe)) {
            $bad = 1;
            next;
        }
        open PROG, "./$exe < one.txt |";
        my $output = <PROG>;
        close PROG;
        chomp $output;
        if (exists $map{$output}) {
            my @l = @{$map{$output}};
            push @l, $who;
            $map{$output} = \@l;
        } else {
            my @l = ($who);
            $map{$output} = (\@l);
        }
    }
    print "--------------------------------------------------------------\n";
    print "triangle: $line\n";
    my $n = 0;
    foreach my $k (sort bypop keys %map) {
        $n++;
        print "'$k' was printed by: ";
        my @l = @{$map{$k}};
        foreach my $who (@l) {
            print "$who ";
        }
        print "\n";
    }
    $bad = 1 if ($n > 1);
    print "\n";
}

if ($bad) {
    exit -1;
} else {
    exit 0;
}
