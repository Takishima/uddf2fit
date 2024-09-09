// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "purchaseType.hxx"

#include "priceType.hxx"

#include "shopType.hxx"

namespace streit
{
  // purchaseType
  //

  const purchaseType::datetime_optional& purchaseType::
  datetime () const
  {
    return this->datetime_;
  }

  purchaseType::datetime_optional& purchaseType::
  datetime ()
  {
    return this->datetime_;
  }

  void purchaseType::
  datetime (const datetime_type& x)
  {
    this->datetime_.set (x);
  }

  void purchaseType::
  datetime (const datetime_optional& x)
  {
    this->datetime_ = x;
  }

  void purchaseType::
  datetime (::std::unique_ptr< datetime_type > x)
  {
    this->datetime_.set (std::move (x));
  }

  const purchaseType::price_optional& purchaseType::
  price () const
  {
    return this->price_;
  }

  purchaseType::price_optional& purchaseType::
  price ()
  {
    return this->price_;
  }

  void purchaseType::
  price (const price_type& x)
  {
    this->price_.set (x);
  }

  void purchaseType::
  price (const price_optional& x)
  {
    this->price_ = x;
  }

  void purchaseType::
  price (::std::unique_ptr< price_type > x)
  {
    this->price_.set (std::move (x));
  }

  const purchaseType::shop_optional& purchaseType::
  shop () const
  {
    return this->shop_;
  }

  purchaseType::shop_optional& purchaseType::
  shop ()
  {
    return this->shop_;
  }

  void purchaseType::
  shop (const shop_type& x)
  {
    this->shop_.set (x);
  }

  void purchaseType::
  shop (const shop_optional& x)
  {
    this->shop_ = x;
  }

  void purchaseType::
  shop (::std::unique_ptr< shop_type > x)
  {
    this->shop_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // purchaseType
  //

  purchaseType::
  purchaseType ()
  : ::xml_schema::type (),
    datetime_ (this),
    price_ (this),
    shop_ (this)
  {
  }

  purchaseType::
  purchaseType (const purchaseType& x,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    datetime_ (x.datetime_, f, this),
    price_ (x.price_, f, this),
    shop_ (x.shop_, f, this)
  {
  }

  purchaseType::
  purchaseType (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    datetime_ (this),
    price_ (this),
    shop_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void purchaseType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // datetime
      //
      if (n.name () == "datetime" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< datetime_type > r (
          datetime_traits::create (i, f, this));

        if (!this->datetime_)
        {
          this->datetime_.set (::std::move (r));
          continue;
        }
      }

      // price
      //
      if (n.name () == "price" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< price_type > r (
          price_traits::create (i, f, this));

        if (!this->price_)
        {
          this->price_.set (::std::move (r));
          continue;
        }
      }

      // shop
      //
      if (n.name () == "shop" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< shop_type > r (
          shop_traits::create (i, f, this));

        if (!this->shop_)
        {
          this->shop_.set (::std::move (r));
          continue;
        }
      }

      break;
    }
  }

  purchaseType* purchaseType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class purchaseType (*this, f, c);
  }

  purchaseType& purchaseType::
  operator= (const purchaseType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->datetime_ = x.datetime_;
      this->price_ = x.price_;
      this->shop_ = x.shop_;
    }

    return *this;
  }

  purchaseType::
  ~purchaseType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const purchaseType& i)
  {
    if (i.datetime ())
    {
      o << ::std::endl << "datetime: " << *i.datetime ();
    }

    if (i.price ())
    {
      o << ::std::endl << "price: " << *i.price ();
    }

    if (i.shop ())
    {
      o << ::std::endl << "shop: " << *i.shop ();
    }

    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

