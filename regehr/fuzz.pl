#!/usr/bin/perl -w

use strict;

my @whos;

open INF, "find .. -name triangle.cpp |" or die;
while (my $line = <INF>) {
    chomp $line;
    die unless ($line =~ /\.\.\/([a-zA-Z0-9]+)\//);
    my $who = $1;
    print "============================================================================\n";
    print "compiling $line to triangle-${who}\n";
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

for (my $t=0; $t<1000; $t++) {
    my $cmd = "";
    for (my $i=0; $i<6; ++$i) {
        $cmd .= int(rand(101)) . " ";
    }
    $cmd .= "\n";
    open OUTF, ">one.txt" or die;
    print OUTF $cmd;
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
    my $out = "--------------------------------------------------------------\n";
    $out .= "triangle: $cmd\n";
    my $n = 0;
    foreach my $k (sort bypop keys %map) {
        $n++;
        $out .= "'$k' was printed by: ";
        my @l = @{$map{$k}};
        foreach my $who (@l) {
            $out .= "$who ";
        }
        $out .= "\n";
    }
    if ($n > 1) {
        $bad = 1;
        print $out;
        print "\n";
    }
}

if ($bad) {
    exit -1;
} else {
    exit 0;
}

