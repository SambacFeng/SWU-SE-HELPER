package exp.exp8;

class URIRequest {
    String protocol;
    String hostname;
    String path;

    public URIRequest(String URI) {
        this.protocol = URI.split("://")[0];
    }
}

abstract class URIHandler {
    private URIHandler successor;

    public URIHandler(URIHandler successor) {
        this.successor = successor;
    }

    public void request(URIRequest request) {
        if (getSuccessor() != null) {
            getSuccessor().request(request);
        } else {
            throw new RuntimeException("Unspported Request!");
        }
    }

    public URIHandler getSuccessor() {
        return successor;
    }

    public void setSuccessor(URIHandler successor) {
        this.successor = successor;
    }
}

class httpUnit extends URIHandler {
    public httpUnit(URIHandler successor) {
        super(successor);
    }

    @Override
    public void request(URIRequest request) {
        if (request.protocol.equals("http"))
            System.out.println("Http");
        else
            super.request(request);
    }
}

class FTPUnit extends URIHandler {
    public FTPUnit(URIHandler successor) {
        super(successor);
    }

    @Override
    public void request(URIRequest request) {
        if (request.protocol.equals("ftp"))
            System.out.println("FTP");
        else
            super.request(request);
    }
}

class mailtoUnit extends URIHandler {
    public mailtoUnit(URIHandler successor) {
        super(successor);
    }

    @Override
    public void request(URIRequest request) {
        if (request.protocol.equals("mailto"))
            System.out.println("Mailto");
        else
            super.request(request);
    }
}

public class URI {
    public static void main(String[] args) {
        URIHandler hanlderChain = new httpUnit(new FTPUnit(new mailtoUnit(null)));
        URIRequest request = new URIRequest("http://localhost/test.html");
        hanlderChain.request(request);
    }
}